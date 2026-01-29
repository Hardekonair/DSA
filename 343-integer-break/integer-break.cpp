class Solution {
public:
    vector<int>dp;
    int fn(int n){
        if(n==1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        int res=-1;
        for(int i=1;i<n;i++){
            int prod=max(i*(n-i),i*fn(n-i));
            res=max(res,prod);
        }
        return dp[n]=res;
    }
    int integerBreak(int n) {
        dp.resize(n+1,-1);
        return fn(n);
    }
};