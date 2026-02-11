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
    int fn(vector<int>& prices,int fee){
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));

        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j==1)
                    dp[i][j]=max(dp[i+1][j],dp[i+1][0]-prices[i]-fee);
                else
                    dp[i][j]=max(dp[i+1][j],dp[i+1][1]+prices[i]);
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(prices.size(),vector<int>(2,-1));
        // return fn(0,1,prices,fee);
        return fn(prices,fee);
    }
};