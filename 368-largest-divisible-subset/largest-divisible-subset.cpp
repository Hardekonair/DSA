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
    vector<int>fn(vector<int>& nums){
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxlen=1,lastind=0;
        vector<int>dp(n,1),par(n,-1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1 ){
                    dp[i]=1+dp[j];
                    par[i]=j;
                }
            }
            if(maxlen<dp[i]){
                maxlen=dp[i];
                lastind=i;
            }
        }
        vector<int>ans(maxlen,0);
        int p=lastind;
        int k=maxlen-1;
        while(p!=-1){
            ans[k--]=nums[p];
            p=par[p];
        }
        return ans;
    }
    vector<int> fn1(vector<int>&nums){          // APPROACH SIMILAR TO LIS
        vector<int> dp(nums.size(),1), hash(nums.size());
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
        vector<int> temp,ans;
        // fn(nums.size()-1,temp,ans,nums);
        // return ans;
        return fn(nums);
    }
};