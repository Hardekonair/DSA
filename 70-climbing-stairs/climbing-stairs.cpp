class Solution {
public:
    // void helper(int i,int n,int& ans, vector<int> & dp){
    //     if(i==n){
    //         ans++;
    //         dp[i]=ans;
    //         return;
    //     }
    //     if(i>n){
    //         return ;}
    //     if(dp[i]!=-1){
    //         ans+=dp[i];
    //         return;
    //     }
    //     helper(i+1,n,ans,dp);  
    //     helper(i+2,n,ans,dp);
    // }
    void helper(int i, int n, int& ans, vector<int>& dp) {
    if (i == n) {
        ans++;
        return;
    }
    if (i > n) return;

    // if this state is already computed, skip further recursion
    if (dp[i] != -1) {
        ans += dp[i]; // add precomputed number of ways
        return;
    }

    int before = ans; // store ans before this recursion
    helper(i + 1, n, ans, dp);
    helper(i + 2, n, ans, dp);
    dp[i] = ans - before; // ways found from this index
}

    int climbStairs(int n) {
        // if(n==0 || n==1)
        //     return 1;
        
        // return climbStairs(n-1)+climbStairs(n-2);

                            // similar to fibbonacci
        // if(n==0 || n==1)
        //     return 1;

        // int a=1,b=1;

        // for(int i=2;i<=n;i++){
        //     int ans=a+b;
        //     a=b;
        //     b=ans;
        // }
        // return b;

                                // BFS TRAVERSAL APPROACH
        
        int ans=0;
        vector<int>dp(n+2,-1);
        helper(0,n,ans,dp);
        return ans;
    }
};