class Solution {
public:
    vector<int>dp;
    int climbstair(int n){
        if(n<0)
            return 0;
        if(n==0)
            return 1;
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

//     void helper(int i, int n, int& ans, vector<int>& dp) {
//     if (i == n) {
//         ans++;
//         return;
//     }
//     if (i > n) return;

//     // if this state is already computed, skip further recursion
//     if (dp[i] != -1) {
//         ans += dp[i]; // add precomputed number of ways
//         return;
//     }

//     int before = ans; // store ans before this recursion
//     helper(i + 1, n, ans, dp);
//     helper(i + 2, n, ans, dp);
//     dp[i] = ans - before; // ways found from this index
// }

    int helper(int n,vector<int>& dp){
        if(n==0)
            return 1;
        if(n<0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=helper(n-1,dp)+helper(n-2,dp);
    }


    // int t[48];  // globally declaring dp
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
                                // using private dp
        // vector<int>dp(n+2,-1);
        // return helper(n,dp);
        dp.resize(n+1,-1);
        return climbstair(n);
    
                        // using global dp
        // memset(t,-1,sizeof(t));       // memory allocation of global dp array
        // vector.resize(47,-1);      for memory alloc in vector
       
    
    
    }
};