class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int temp=0;
        for(auto it:costs){
            if(coins>=it){
                coins-=it;
                temp++;
            }
        }
        return temp;
    }
};