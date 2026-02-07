class Solution {
public:
    vector<vector<int>> dp;
    // RECURSION
    int helper1(vector<int>& nums,int target,int i){
        if(target<0)
            return 0;
        if(i<0){
            if(target==0)
                return 1;
            return 0;
        }

        int pos=helper1(nums,target-nums[i],i-1);
        int neg=helper1(nums,target+nums[i],i-1);

        return pos+neg;
    }
    // MEMOIZATION
    int helper2(vector<int>& nums,int target,int i){
        if(target<0 || target>2000)     // IMPORTANT
            return 0;
        if(i<0){
            if(target==1000)
                return 1;
            return 0;
        }
        
        if(dp[i][target]!=-1)
            return dp[i][target];

        int pos=helper2(nums,target-nums[i],i-1);
        int neg=helper2(nums,target+nums[i],i-1);

        return dp[i][target]=pos+neg;
    }
    // TABULATION
    int helper3(vector<int>& nums,int target){
        vector<vector<int>>dp(nums.size(),vector<int>(2001,0));
        // if(target<0 || target>2000)     // IMPORTANT
        //     return 0;
        if(target+1000<0 || target+1000>2000)
            return 0;
        // if(i<0){
        //     if(target==1000)
        //         return 1;
        //     return 0;
        // }
        dp[0][1000+nums[0]]+=1;
        dp[0][1000-nums[0]]+=1;
        
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<=2000;j++){
                if(j-nums[i]>=0)
                    dp[i][j]+=dp[i-1][j-nums[i]];
                if(j+nums[i]<=2000)
                    dp[i][j]+=dp[i-1][j+nums[i]];
            }
        }

        return dp[nums.size()-1][target+1000];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int c=1000;
        dp.resize(nums.size(),vector<int>(2001,-1));
        // return helper(nums,target+1000,nums.size()-1,c);
        // return helper2(nums,target+1000,nums.size()-1);
        return helper3(nums,target);
    }
};