class Solution {
public:
    vector<vector<int>>dp;
    int fn(int i,int canbuy,vector<int>& prices,int fee){
        if(i==prices.size())
            return 0;
        if(dp[i][canbuy]!=-1)   
            return dp[i][canbuy];
        if(canbuy==1){
            return dp[i][canbuy]=max(0+fn(i+1,canbuy,prices,fee),-prices[i]-fee+fn(i+1,!canbuy,prices,fee));
        }
        else
            return dp[i][canbuy]=max(0+fn(i+1,canbuy,prices,fee),prices[i]+fn(i+1,!canbuy,prices,fee));
    }
    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return fn(0,1,prices,fee);
    }
};