class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp=matrix;

        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==1)
                    dp[i][j]+=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
        }
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};