class Solution {
public:
    int dp[100][100];
    int solve(int i,int j,vector<int>& colors){
        if(colors[i]!=colors[j])
            return abs(j-i);
        if(dp[i][j]!=-1)    
            return dp[i][j];
        return dp[i][j]=max(solve(i+1,j,colors),solve(i,j-1,colors));
    }
    int maxDistance(vector<int>& colors) {
        memset(dp,-1,sizeof(dp));
        return solve(0,colors.size()-1,colors);
    }
};