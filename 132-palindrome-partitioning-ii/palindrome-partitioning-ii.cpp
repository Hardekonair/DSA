class Solution {
public:
    vector<vector<int>> dpp;
    vector<int> dp;
    bool ispalin(int i,int j,string& s){
        while(i<j && s[i]==s[j]){
            i++;j--;
        }
        if(i>=j)
            return true;
        return false;
    }
    int fn(int i,int j,string& s){
        if(ispalin(i,j,s))
            return 0;
        if(i==j)    
            return 0;
        if(i>j) 
            return 1e9;
        if(dpp[i][j]!=-1)
            return dpp[i][j];
        int ans=1e9;
        for(int k=i;k<j;k++){
            int temp=1+fn(i,k,s)+fn(k+1,j,s);
            ans=min(ans,temp);
        }
        return dpp[i][j]=ans;
    }
    int tabulation(string s){
        int n=s.size();
        vector<vector<bool>>palin(n,vector<bool>(n,0));
        for(int i=0;i<n;i++){
            palin[i][i]=1;
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                if(len==2)
                    palin[i][j]=(s[i]==s[j]);
                else
                    palin[i][j]=(s[i]==s[j]) && palin[i+1][j-1]; 
            }
        }

        vector<int>dp(n);
        for(int i=0;i<n;i++){
            if(palin[0][i])
                dp[i]=0;
            else{
                dp[i]=1e9;
                for(int k=0;k<i;k++){
                    if(palin[k+1][i] && 1+dp[k]<dp[i])
                        dp[i]=1+dp[k];
                }
            }
        }
        return dp[n-1];
    }
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
        // PRECOMPUTING PALL TABLE COZ ISPAL() TAKING LOT OF MEMORY
        vector<vector<int>> pall(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){   // WE ARE COMPUTING FROM N-1 AS WE NEED TO CHECK (I+1,J-1) PRECOMPUTED
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
        dpp.resize(s.size(),vector<int>(s.size(),-1));
        // return pp(s,0)-1;
        // return pp1(s);
        // return fn(0,s.size()-1,s);
        return tabulation(s);
    }
};