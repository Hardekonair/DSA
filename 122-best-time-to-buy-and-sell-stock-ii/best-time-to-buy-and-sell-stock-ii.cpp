class Solution {
public:
    vector<vector<int>>dp;
    int maxp(vector<int>& prices,int i,int buy){
        if(i==prices.size())
            return 0;
        
        if(dp[i][buy]!=-1)
            return dp[i][buy];

        if(i!=prices.size() && buy){    // CAN BUY      return  max(dont buy and move . buy and move)
            return dp[i][buy]=max(-0+maxp(prices,i+1,1),-prices[i]+maxp(prices,i+1,0));
        }
        else {    // CAN'T BUY    return max(sell and move, dont sell and move)
            return dp[i][buy]=max(prices[i]+maxp(prices,i+1,1),maxp(prices,i+1,0));
        }

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

    int maxp2(vector<int>& prices){
        // vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        vector<int> next(2,0),curr(2,0);

        // dp[prices.size()][0]=0;
        // dp[prices.size()][1]=0;
        next[0]=next[1]=0;

        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<2;j++){
                int profit=0;
                if(j){
                    profit=max(-prices[i]+next[0],0+next[j]);
                
                }
                else if(!j){
                    profit=max(prices[i]+next[1],0+next[j]);
                }
                curr[j]=profit;
            }
            next=curr;
        }
        return next[1];
    }
    int maxp3(vector<int>& prices){
        // vector<int> next(2,0),curr(2,0);
        // next[0]=next[1]=0;

        int nextnotbuy=0,nextbuy=0;
        int currnotbuy=0,currbuy=0;

        for(int i=prices.size()-1;i>=0;i--){
                int profit=0;
                currbuy=max(-prices[i]+nextnotbuy,0+nextbuy);
                currnotbuy=max(prices[i]+nextbuy,0+nextnotbuy);

                nextbuy=currbuy;
                nextnotbuy=currnotbuy;
        }
        return nextbuy;
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return maxp(prices,0,1);
        // return maxp1(prices);
        // return maxp3(prices);
    }
};