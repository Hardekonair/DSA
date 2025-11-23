class Solution {
public:
    // void fn(vector<int>&nums,int i,vector<int>& temp,vector<int>& ans){

    //     if(i==nums.size()){
    //         if(temp.size()>ans.size())
    //             ans=temp;
    //         return;
    //     }
    //     if(temp.empty() || nums[i]%temp.back()==0){
    //         temp.push_back(nums[i]);
    //         fn(nums,i+1,temp,ans);
    //         temp.pop_back();
    //     }
    //     fn(nums,i+1,temp,ans);
    // }

    vector<int> fn(vector<int>&nums){
        vector<int> dp(nums.size(),1),hash(nums.size());
        int maxlen=0,lastind=0;
        
        for(int i=1;i<nums.size();i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    hash[i]=j;
                    dp[i]= dp[j]+1 ;
                    
                }
            }
            if(dp[i]>maxlen){
                maxlen=dp[i];
                lastind=i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastind]);
        while(lastind && hash[lastind]!=lastind){
            lastind=hash[lastind];
            ans.push_back(nums[lastind]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return fn(nums);
    }
};