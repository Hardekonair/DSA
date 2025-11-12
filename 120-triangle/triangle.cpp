class Solution {
public:

    vector<vector<int>>dp;
                                // MEMOIZATION
    int help(vector<vector<int>>& t,int i,int j,int n){
        if(i==n-1)
            return t[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int d=t[i][j]+help(t,i+1,j,n);
        int dg=t[i][j]+help(t,i+1,j+1,n);

        return dp[i][j]=min(d,dg);
    }

                            // TABULATION
    int help2(vector<vector<int>>& t,int n){
        for(int i=0;i<n;i++){
            dp[n-1][i]=t[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                dp[i][j]=t[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }

    //  TABULATION - SPACE OPT
    int help3(vector<vector<int>>& t,int n){
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            dp[i]=t[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
            vector<int> temp(n,0);
            for(int j=i;j>=0;j--){
                temp[j]=t[i][j]+min(dp[j],dp[j+1]);
            }
            dp=temp;
        }
        return dp[0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        dp.resize(n,vector<int>(n,-1));
        return help3(triangle,n);
    }
};