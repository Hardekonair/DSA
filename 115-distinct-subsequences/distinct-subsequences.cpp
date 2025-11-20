class Solution {
public:
    vector<vector<int>> dp;
    int countdistinct(string s,string t,int i,int j){
        if(j<0)
            return 1;
        if(i<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j]=countdistinct(s,t,i-1,j-1)+countdistinct(s,t,i-1,j);
        else
            return dp[i][j]=countdistinct(s,t,i-1,j);
    }
    int numDistinct(string s, string t) {
        dp.resize(s.size(),vector<int>(t.size(),-1));
        return countdistinct(s,t,s.size()-1,t.size()-1);
    }
};