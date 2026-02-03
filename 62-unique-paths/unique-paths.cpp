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
    int fn(int m,int n){
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

                                    // SPACE OPTIMIZED DP
    int helper4(int m,int n){

        vector<int> dp(n,1);        //BASE CASE - ONLY 1 PATH EXIST
        for(int i=1;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                temp[j]=dp[j];
                if(j-1>=0)
                    temp[j]+=temp[j-1];
            }
            dp=temp;
        }
        return dp[n-1];
    }
    int uniquePaths(int m, int n) {
        dp.resize(100,vector<int>(100,-1));

        // return helper4(m,n);
        return fn(m,n);
    }
};