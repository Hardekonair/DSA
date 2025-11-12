class Solution {
public:
    vector<vector<int>> dp;

                                    // RECURSION
    int helper(int m,int n){
        if(m==0 && n==0)
            return 1;
        
        if(m<0 || n<0)
            return 0;

        int up=helper(m-1,n);
        int down=helper(m,n-1);

        return up+down;
    }
                                    // RECURSION - MEMOIZATION
    int helper2(int m,int n){
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

                                    // TABULATION 1
    int helper3(int m,int n){
        // if(m==0 && n==0)
        //     return 1;
        
        // if(m<0 || n<0)
        //     return 0;

        vector<vector<int>> dpp(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                    dpp[i][j]=1;        // BASE CASE;
                else{
                    if(i-1>=0)
                        dpp[i][j]+=dpp[i-1][j];
                    if(j-1>=0) 
                        dpp[i][j]+= dpp[i][j-1];

                }
            }
        }
        return dpp[m-1][n-1];
    }

                                    // SPACE OPTIMIZED DP
    int helper4(int m,int n){
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

        return helper3(m,n);
    }
};