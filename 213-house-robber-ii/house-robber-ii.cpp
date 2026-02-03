class Solution {
public:                 
                                            // NOT NECESSARY
    // vector<vector<int>>dp;
    // int houserobber2(int i,vector<int>& nums,bool last){
    //     if(i<0) return 0;
    //     if(i==0 && last)    return 0;
    //     if(i==0 && last==false)    return nums[0];
    //     if(dp[i][last]!=-1)
    //         return dp[i][last];
    //     int notpick=houserobber2(i-1,nums,last);
    //     int pick=0;
    //     if(i==nums.size()-1)
    //         last=true;
    //     pick=nums[i]+houserobber2(i-2,nums,last);
        
    //     return dp[i][last]=max(pick,notpick);
        
    // }
    int helper(vector<int> nums){    // SAME AS HOUSE ROBBER 1
        int prev1=nums[0], prev2=0;

        for(int i=1;i<nums.size();i++){
            int pick=nums[i]+prev2;
            int notpick=0+prev1;

            int cur=max(pick,notpick);
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
    }
    vector<int>dp;
    int helper1(int i,int j,vector<int>& nums){
        if(i==j)
            return nums[i];
        if(i<j)
            return 0;

        if(dp[i]!=-1)
            return dp[i];

        int pick=nums[i]+helper1(i-2,j,nums);
        int notpick=0+helper1(i-1,j,nums);

        // return max(pick,notpick);
        return dp[i]=max(pick,notpick);
    }
    int helper2(int i,int j,vector<int>& nums){      // BASIC TABULATION
        if(j-i+1==1)  // MUST REMEMBER THIS EDGE CASE
            return nums[i];

        dp[i]=nums[i];
        dp[i+1]=max(nums[i],nums[i+1]);

        for(int k=i+2;k<=j;k++){
            int pick=nums[k]+dp[k-2];
            int notpick=0+dp[k-1];
            dp[k]=max(pick,notpick);
        }

        return dp[j];
    }
    int rob(vector<int>& nums) {
        // vector<int> t1,t2;
        int n=nums.size();
        if(n==1)
            return nums[0];

        // if(n==1)
        //     return nums[0];
        // for(int i=0;i<n;i++){
        //     if(i!=n-1)
        //         t1.push_back(nums[i]);
        //     if(i!=0)
        //         t2.push_back(nums[i]);
        // }

        // return max(helper(t1),helper(t2));
        // dp.resize(n,-1);
        dp.resize(n,0);
        // int a=helper1(n-1,1,nums);
        int a=helper2(1,n-1,nums);
        // dp.assign(n,-1);
        dp.assign(n,0);

        int b=helper2(0,n-2,nums);
        return max(a,b);
        // dp.resize(n,vector<int>(n,-1));
        // return houserobber2(n-1,nums,false);
        
    }
};