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

    int fn1(vector<int>& prices,int t){
        // in dp size we do prices.size()+1, because we have a base case where i==n, return 0;
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(t+1,-1)));
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
            for(int k=0;k<t+1;k++){
                dp[prices.size()][j][k]=0;
            }
        }

        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<t+1;k++){
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
        return dp[0][1][t];
    }
    int maxProfit(int k, vector<int>& prices) {
        // dp.resize(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));

        return fn1(prices,k);
    }
};