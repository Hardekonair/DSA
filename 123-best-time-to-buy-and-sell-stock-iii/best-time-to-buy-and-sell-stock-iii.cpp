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

    int maxp1(vector<int>& prices){
        // in dp size we do prices.size()+1, because we have a base case where i==n, return 0;
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
        // if(trans==0)
        //     return 0;
        for(int i=0;i<prices.size()+1;i++){
            for(int j=0;j<2;j++){
                dp[i][j][0]=0;
            }
        }

        // if(i==prices.size())
        //     return 0;
        for(int j=0;j<2;j++){
            for(int k=0;k<3;k++){
                dp[prices.size()][j][k]=0;
            }
        }

        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<3;k++){
                    int profit=0;
                    if(j){
                        profit=max(-prices[i]+dp[i+1][0][k],0+dp[i+1][1][k]);

                    }
                    else{
                        profit=max(prices[i]+dp[i+1][1][k-1],0+dp[i+1][0][k]);
                        
                    }
                    dp[i][j][k]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));    // 3, bcause 1,2 are countable, at 0 the recursion stops so we didn't consider 
        // return maxpr(prices,0,1,2);     // 2nd trans-> 1st trans-> 0th->stop recursion
        return maxp1(prices);
    }
};