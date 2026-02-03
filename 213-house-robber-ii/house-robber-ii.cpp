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
        dp.resize(n,-1);
        int a=helper1(n-1,1,nums);
        dp.assign(n,-1);

        int b=helper1(n-2,0,nums);
        return max(a,b);
        // dp.resize(n,vector<int>(n,-1));
        // return houserobber2(n-1,nums,false);
        
    }
};