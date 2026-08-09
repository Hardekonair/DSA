class Solution {
public:
    int dp[501][501];

    int solve(int i,int j, vector<int>& piles){
        if(i>j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int pick_i=piles[i]+min(solve(i+2,j,piles),solve(i+1,j-1,piles));
        
        int pick_j=piles[j]+min(solve(i,j-2,piles),solve(i+1,j-1,piles));

        return dp[i][j]=max(pick_i,pick_j);
    }

    bool stoneGame(vector<int>& piles) {
        
        int n=piles.size();

        memset(dp,-1,sizeof(dp));

        int totalsum=accumulate(piles.begin(),piles.end(),0);

        int alice_count=solve(0,n-1,piles);
        int bob_count=totalsum-alice_count;

        if(alice_count>bob_count)
            return true;
        return false;
    }
};