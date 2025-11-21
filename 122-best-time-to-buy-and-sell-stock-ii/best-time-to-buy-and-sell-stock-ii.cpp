class Solution {
public:
    vector<vector<int>>dp;
    int maxp(vector<int>& prices,int i,int buy){
        if(i==prices.size())
            return 0;
        
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        int profit=0;
        if(buy){
            profit=max(-prices[i]+maxp(prices,i+1,0),0+maxp(prices,i+1,1));

        }
        else if(buy==0){
            profit=max(prices[i]+maxp(prices,i+1,1),maxp(prices,i+1,0));
        }
        return dp[i][buy]=profit;
    }

    int maxp1(vector<int>& prices){
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        // if(i==prices.size())
        //     return 0;
        dp[prices.size()][0]=0;
        dp[prices.size()][1]=0;

        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<2;j++){
                int profit=0;
                if(j){
                    profit=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
                
                }
                else if(!j){
                    profit=max(prices[i]+dp[i+1][1],0+dp[i+1][0]);
                }
                dp[i][j]=profit;
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int>(2,-1));
        // return maxp(prices,0,1);
        return maxp1(prices);
    }
};