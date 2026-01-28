class Solution {
public:
    vector<vector<int>>d={{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>>dp;
    int dfs(int i,int j,vector<vector<int>>& matrix){

        if(dp[i][j]!=-1)
            return dp[i][j];
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=1;
        for(int k=0;k<4;k++){
            int ni=i+d[k][0];
            int nj=j+d[k][1];
            if(ni>=0 && ni<n && nj>=0 && nj<m && matrix[ni][nj]>matrix[i][j]){
                ans=max(ans,1+dfs(ni,nj,matrix));
            }
        }
        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        dp.resize(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,dfs(i,j,matrix));
            }
        }
        return ans;
    }
};