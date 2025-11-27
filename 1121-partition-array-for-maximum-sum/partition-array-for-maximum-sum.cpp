class Solution {
public:
    vector<int> dp;
    int partsum(vector<int>& arr,int k,int i){
        if(i==arr.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int len=0,maxi=0;
        int maxcost=0;
        for(int j=i;j<min(k+i,(int)arr.size());j++){
            len++;
            maxi=max(maxi,arr[j]);
            int cost=len*maxi+partsum(arr,k,j+1);
            maxcost=max(maxcost,cost);
        }
        return dp[i]=maxcost;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size(),-1);
        return partsum(arr,k,0);
    }
};