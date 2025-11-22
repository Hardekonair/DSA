class Solution {
public:
    vector<vector<vector<int>>>dp;
    int fn(vector<int>& prices,int i,int buy,int k){
        if(k==0)
            return 0;
        if(i==prices.size())
            return 0;

        if(dp[i][buy][k]!=-1)
            return dp[i][buy][k];

        int profit=0;
        if(buy){
            profit= max(-prices[i]+fn(prices,i+1,0,k), 0+fn(prices,i+1,1,k));

        }
        else{
            profit=max(prices[i]+fn(prices,i+1,1,k-1),0+fn(prices,i+1,0,k)); 
        }
        return dp[i][buy][k]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        dp.resize(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));

        return fn(prices,0,1,k);
    }
};