class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& coins,int amount, int i){
        if(amount==0)
            return 0;
        else if(i==0 ){
            if(amount!=0 && amount%coins[i]==0)
                return amount/coins[i];
            return 1e9;       
        }
        if(dp[i][amount]!=-1)
            return dp[i][amount];

        int notpick=helper(coins,amount,i-1);
        int pick=1e9;
        if(coins[i]<=amount)
            pick=helper(coins,amount-coins[i],i);
        
        return dp[i][amount]=min(pick+1,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size(),vector<int>(amount+1,-1));
        return helper(coins,amount,coins.size()-1)==1e9?-1:helper(coins,amount,coins.size()-1);
    }
};