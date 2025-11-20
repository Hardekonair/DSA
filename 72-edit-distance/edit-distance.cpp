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
    int minDistance(string word1, string word2) {
        dp.resize(word1.size(),vector<int>(word2.size(),-1));
        return minopt(word1,word2,word1.size()-1,word2.size()-1);
        
    }
};