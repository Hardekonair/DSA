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

        int pick=1e9;
        if(coins[i]<=amount)
            pick=helper(coins,amount-coins[i],i);
        int notpick=helper(coins,amount,i-1);
        
        return dp[i][amount]=min(pick+1,notpick);
    }


    int helper1(vector<int>& coins,int amount){
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,0));
        
        // if(amount==0)
        //     return 0;
        for(int i=0;i<coins.size();i++){
            dp[i][0]=0;
        }

        // else if(i==0 ){
        //     if(amount!=0 && amount%coins[i]==0)
        //         return amount/coins[i];
        //     return 1e9;
        for(int i=1;i<amount+1;i++){
            dp[0][i]=i%coins[0]==0?(i/coins[0]):1e9;
        }

        for(int i=1;i<coins.size();i++){
            for(int j=1;j<=amount;j++){
                int pick=1e9;
                if(coins[i]<=j)
                    pick=1+dp[i][j-coins[i]];
                int notpick=dp[i-1][j];

                dp[i][j]=min(pick,notpick);
            }
        }
        return dp[coins.size()-1][amount]==1e9?-1:dp[coins.size()-1][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size(),vector<int>(amount+1,-1));
        // return helper(coins,amount,coins.size()-1)==1e9?-1:helper(coins,amount,coins.size()-1);
        return helper1(coins,amount);
    }
};