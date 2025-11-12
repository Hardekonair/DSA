class Solution {
public:
    vector<vector<int>> dp;

                                    // RECURSION
    int helper1(vector<vector<int>>& mat,int m,int n){
        if(m<0 || n<0 || n>=mat[0].size())
            return INT_MAX;
        if(m==0)
            return mat[m][n];

        int left=helper1(mat,m-1,n-1);
        int up=helper1(mat,m-1,n);
        int right=helper1(mat,m-1,n+1);

        int dir=min({left,up,right});
        if(dir==INT_MAX)
            return mat[m][n];
        else 
            return mat[m][n]+dir;

    }

                                    // MEMOIZATION
    int helper2(vector<vector<int>>& mat,int m,int n){
        if(m<0 || n<0 || n>=mat[0].size())
            return INT_MAX;
        if(m==0)
            return mat[m][n];
        if(dp[m][n]!=-1)
            return dp[m][n];


        int left=helper1(mat,m-1,n-1);
        int up=helper1(mat,m-1,n);
        int right=helper1(mat,m-1,n+1);

        int dir=min({left,up,right});
        if(dir==INT_MAX)
            return dp[m][n]=mat[m][n];
        else 
            return dp[m][n]=mat[m][n]+dir;

    }

                                // TABULATION
    int helper3(vector<vector<int>>& mat,int m,int n){
        for(int i=0;i<n;i++){
            dp[0][i]=mat[0][i];
        }
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int left=INT_MAX,right=INT_MAX;
                if(j-1>=0)
                    left=dp[i-1][j-1];
                int up=dp[i-1][j];
                if(j+1<n)
                    right=dp[i-1][j+1];
                
                int dir=min({left,up,right});
                dp[i][j]=mat[i][j]+dir;
            }
        }
        int ans=INT_MAX;
        for(auto it:dp[m-1])
        ans=min(ans,it);

        return ans;

    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int m=mat.size();
        dp.resize(m,vector<int>(m,-1));
        // int ans=INT_MAX;
        // for(int i=0;i<m;i++)
        // ans=min(ans,helper1(matrix,matrix.size()-1,i)) ;

        // return ans;


        return helper3(mat,m,m);
    }
};