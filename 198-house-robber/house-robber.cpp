class Solution {
public:
    int dp[100];
    int helper(int i,vector<int>& nums){
        if(i==0)
            return nums[i];
        if(i<0)
            return 0;

        if(dp[i]!=-1)
            return dp[i];

        int pick=nums[i]+helper(i-2,nums);
        int notpick=0+helper(i-1,nums);

        return dp[i]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return helper(nums.size()-1,nums);
        
    }
};