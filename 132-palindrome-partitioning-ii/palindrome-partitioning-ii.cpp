class Solution {
public:
    vector<int> dp;
    bool ispalin(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])  
                return false;
            i++;
            j--;
        }
        return true;
    }
    int pp(string s,int i){
        if(i>s.size()-1)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int mincost=INT_MAX;
        for(int j=i;j<s.size();j++){
            if(ispalin(s,i,j)){
                int cost=1+pp(s,j+1);
                mincost=min(cost,mincost);
            }
        }
        return dp[i]=mincost;
    }

    int pp1(string s){
        int n=s.size();
        vector<int> dp(n+1);
        dp[n]=0;

        vector<vector<int>> pall(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<2 || pall[i+1][j-1]))
                    pall[i][j]=1;
            }
        }
    
        for(int i=n-1;i>=0;i--){
            int mincost=INT_MAX;
            for(int j=i;j<n;j++){
                if(pall[i][j]){
                    int cost=1+dp[j+1];
                    mincost=min(mincost,cost);
                }
            }
            dp[i]=mincost;
            
        }

        return dp[0]-1;
    }
    int minCut(string s) {
        // dp.resize(s.size(),-1);
        // return pp(s,0)-1;
        return pp1(s);
    }
};