class Solution {
public:
    int maxProfit(vector<int>& price) {
        int buy=price[0];      // minimum buying price
        int maxp=0; 
        int n=price.size();
        for(int i=1;i<n;i++){
            int profit=price[i]-buy;    // profit=sell-buy

            maxp=max(profit,maxp);

            buy=min(buy,price[i]);
        }
        return maxp;
        
    }
};