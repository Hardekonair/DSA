class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& nums,int target,int i,int c){
        if(i<0){
            if(target==c)
                return 1;
            return 0;
        }
        if(dp[i][c]!=-1)
            return dp[i][c];

        int pos=helper(nums,target,i-1,c+nums[i]);
        int neg=helper(nums,target,i-1,c-nums[i]);

        return dp[i][c]=pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int c=1000;
        dp.resize(nums.size(),vector<int>(2001,-1));
        return helper(nums,target+1000,nums.size()-1,c);
    }
};