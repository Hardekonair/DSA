class Solution {
public:
    vector<vector<int>>dp;
    int countCoins(vector<int>& coins,int amount, int i){
        if(amount==0)
            return 1;
        if(i==0){
            if(amount%coins[i]==0)
                return 1;
            return 0;
        }
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        int pick=0;
        if(coins[i]<=amount)
            pick=countCoins(coins,amount-coins[i],i);
        int notpick=countCoins(coins,amount,i-1);

        return dp[i][amount]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        dp.resize(coins.size(),vector<int>(amount+1,-1));
        return countCoins(coins,amount,coins.size()-1);
    }
};