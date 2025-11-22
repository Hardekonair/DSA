class Solution {
public:
    vector<vector<int>> dp;
    int maxlen(vector<int>&nums,int i,int next){
        if(i<0)
        return 0;

        if(dp[i][next]!=-1)
            return dp[i][next];

        int l=0,m=0;
        if(next==nums.size() || nums[next]>nums[i])
            l=1+maxlen(nums,i-1,i);
        
        m=0+maxlen(nums,i-1,next);

        return dp[i][next]=max(l,m);
    }
    int lengthOfLIS(vector<int>& nums) {
        // int n=nums.size();
        // int maxi=0;

        // vector<int> ans;
        // ans.push_back(nums[0]);
        // int len=1;

        // for(int i=1;i<n;i++){
        //     if(nums[i]>ans.back()){
        //         ans.push_back(nums[i]);
        //         len++;
        //     }
        //     else{
        //         auto ind=lower_bound(ans.begin(),ans.end(),nums[i]);
        //         *ind=nums[i];
        //     }
        // }
        // return len;

        dp.resize(nums.size(),vector<int>(nums.size()+1,-1));
        return maxlen(nums,nums.size()-1,nums.size());
    }
};