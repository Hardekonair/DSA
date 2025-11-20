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

    long long countdistinct1(string s,string t){
        vector<vector<long long>> dp(s.size()+1,vector<long long>(t.size()+1,0));

        // if(j<0)
        //     return 1;
        for(long long i=0;i<=s.size();i++)
            dp[i][0]=1;

        // if(i<0)
        //     return 0;
        for(long long i=1;i<=s.size();i++){
            for(long long j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[s.size()][t.size()];
    }

    int countdistinct2(string s,string t){

        vector<double>prev(t.size()+1,0);
        vector<double>curr(t.size()+1,0);
        prev[0]=1;
        
        for(double i=1;i<s.size()+1;i++){
            curr[0]=1;
            for(double j=1;j<t.size()+1;j++){
                if(s[i-1]==t[j-1])
                    curr[j]=prev[j-1]+prev[j];
                else
                    curr[j]=prev[j];
            }
            prev=curr;
        }
        return (int)prev[t.size()];
    }
    int numDistinct(string s, string t) {
        dp.resize(s.size(),vector<int>(t.size(),-1));
        // return countdistinct(s,t,s.size()-1,t.size()-1);
        return countdistinct2(s,t);
    }
};