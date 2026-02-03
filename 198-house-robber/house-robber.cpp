class Solution {
public:
    int dp[100];
                            // MEMOIZATION
    int helper1(int i,vector<int>& nums){
        if(i==0)
            return nums[i];
        if(i<0)
            return 0;

        if(dp[i]!=-1)
            return dp[i];

        int pick=nums[i]+helper1(i-2,nums);
        int notpick=0+helper1(i-1,nums);

        return dp[i]=max(pick,notpick);
    }

                                // TABULATION - RECURSION
    int helper2(vector<int>& nums){      // BASIC TABULATION
        if(nums.size()==1)  // MUST REMEMBER THIS EDGE CASE
            return nums[0];

        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for(int i=2;i<nums.size();i++){
            int pick=nums[i]+dp[i-2];
            int notpick=0+dp[i-1];
            dp[i]=max(pick,notpick);
        }

        return dp[nums.size()-1];
    }
                                // TABULATION- NO RECURSION

    int helper3(vector<int>& nums){     // MORE PROF.TABULATION

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

                                    // TABULATION - NO DP ARRAY
    int helper4(vector<int>& nums){
        int prev=nums[0];
        int prev2=0;

        for(int i=1;i<nums.size();i++){
            int pick=nums[i]+prev2;
            int notpick=0+prev;

            int curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
        }

        return prev;
    }

    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        // return helper(nums.size()-1,nums);

        return helper4(nums);
        
    }
};