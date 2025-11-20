class Solution {
public:
    int lcs(string a,string b){
        vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1,0));

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
    int minDistance(string word1, string word2) {
        int n=lcs(word1,word2);
        int a=word1.size()-n;
        int b=word2.size()-n;
        return a+b;
    }
};