class Solution {
public:
    vector<vector<int>> dp;
    int helper(int m,int n){
        if(m==0 && n==0)
            return 1;
        
        if(m<0 || n<0)
            return 0;

        if(dp[m][n]!=-1)
            return dp[m][n];

        int up=helper(m-1,n);
        int down=helper(m,n-1);

        return dp[m][n]=up+down;
    }
    int uniquePaths(int m, int n) {
        dp.resize(100,vector<int>(100,-1));

        return helper(m-1,n-1);
    }
};