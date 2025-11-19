class Solution {
public:
    vector<vector<int>> dp;
    int lcs(string a,string b,int i,int j){
        if(i<0 || j<0)  
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];
        if(a[i]==b[j])
            return dp[i][j]=1+lcs(a,b,i-1,j-1);
        
        return dp[i][j]=max(lcs(a,b,i-1,j),lcs(a,b,i,j-1));
    }

    int lcs1(string a,string b){
        vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,0));
        // for(int i=0;i<a.size();i++){
        //     dp[i][0]=0;
        // }
        // for(int i=0;i<a.size();i++){
        //     dp[0][i]=0;
        // }

        for(int i=1;i<a.size()+1;i++){
            for(int j=1;j<b.size()+1;j++){
                if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[a.size()][b.size()];
    }
    

    int longestPalindromeSubseq(string s) {
        string a=s;
        dp.resize(s.size(),vector<int>(s.size(),-1));
        reverse(a.begin(),a.end());
        // return lcs(s,a,s.size()-1,s.size()-1);
        return lcs1(s,a);
    }
};