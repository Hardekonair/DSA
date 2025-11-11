class Solution {
public:
    int dp[100];
                            // MEMOIZATION
    // int helper(int i,vector<int>& nums){
    //     if(i==0)
    //         return nums[i];
    //     if(i<0)
    //         return 0;

    //     if(dp[i]!=-1)
    //         return dp[i];

    //     int pick=nums[i]+helper(i-2,nums);
    //     int notpick=0+helper(i-1,nums);

    //     return dp[i]=max(pick,notpick);
    // }

                                // TABULATION
    // int helper2(vector<int>& nums){
    //     if(nums.size()==1)
    //         return nums[0];
    //     int ans=INT_MAX;
    //     dp[0]=nums[0];
    //     dp[1]=max(nums[0],nums[1]);
    //     for(int i=2;i<nums.size();i++){
    //         int pick=nums[i]+dp[i-2];
    //         int notpick=0+dp[i-1];
    //         dp[i]=max(pick,notpick);
    //     }

    //     return dp[nums.size()-1];
    // }

    int helper2(vector<int>& nums){
        if(nums.size()==1)
            return nums[0];
        int ans=INT_MAX;
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int pick=nums[i];
            if(i>1)
                pick+=dp[i-2];
            int notpick=0+dp[i-1];
            dp[i]=max(pick,notpick);
        }

        return dp[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        // return helper(nums.size()-1,nums);

        return helper2(nums);
        
    }
};