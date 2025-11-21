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
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return maxp(prices,0,1);
    }
};