class Solution {
public:
    vector<vector<int>>dp;
    int minopt(string a,string b,int i,int j){
        if(j<0)
            return i+1;
        if(i<0)
            return j+1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(a[i]==b[j]) 
            return dp[i][j]=0+minopt(a,b,i-1,j-1);
        else
            return dp[i][j]=1+min({minopt(a,b,i-1,j-1),minopt(a,b,i-1,j),minopt(a,b,i,j-1)});
    }

    int minopt1(string a,string b){
        vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,0));
        // if(j<0)
        //     return i+1;
        for(int i=0;i<a.size()+1;i++)
            dp[i][0]=i;                     // BECAUSE WE MAKE IT 1-INDEX ARRAY NOT 0-INDEX, not i+1
        // if(i<0)
        //     return j+1;
        for(int i=0;i<b.size()+1;i++)
            dp[0][i]=i;

        for(int i=1;i<a.size()+1;i++){
            for(int j=1;j<b.size()+1;j++){
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
        }
        return dp[a.size()][b.size()];
    }
    int minDistance(string word1, string word2) {
        dp.resize(word1.size(),vector<int>(word2.size(),-1));
        // return minopt(word1,word2,word1.size()-1,word2.size()-1);
        return minopt1(word1,word2);
        
    }
};