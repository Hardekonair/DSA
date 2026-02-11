class Solution {
public:
    vector<vector<int>>dp;
    int fn(int i,int canbuy,vector<int>& prices){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][canbuy]!=-1)   
            return dp[i][canbuy];
        if(canbuy==1){
            return dp[i][canbuy]=max(-0+fn(i+1,canbuy,prices),-prices[i]+fn(i+1,!canbuy,prices));
        }
        else{
            return dp[i][canbuy]=max(0+fn(i+1,canbuy,prices),prices[i]+fn(i+2,!canbuy,prices));
        }

    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size()+2,vector<int>(2,-1));
        return fn(0,1,prices);
    }
};