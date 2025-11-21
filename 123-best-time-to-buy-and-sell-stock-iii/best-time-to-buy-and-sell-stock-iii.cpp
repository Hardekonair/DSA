class Solution {
public:
    vector<vector<vector<int>>>dp;
    int maxpr(vector<int>& prices,int i,int buy,int trans){
        if(trans==0)
            return 0;
        if(i==prices.size())
            return 0;
        if(dp[i][buy][trans]!=-1)
            return dp[i][buy][trans];
        int profit=0;
        if(buy){
            profit=max(-prices[i]+maxpr(prices,i+1,0,trans),0+maxpr(prices,i+1,buy,trans));

        }
        else if(buy==0){
            profit=max(prices[i]+maxpr(prices,i+1,1,trans-1),0+maxpr(prices,i+1,buy,trans));
        }
        return dp[i][buy][trans]=profit;
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return maxpr(prices,0,1,2);
    }
};