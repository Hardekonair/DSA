class Solution {
public:
    vector<vector<int>>dp;
    int lcs(string a,string b,int i,int j){
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(a[i]==b[j])  
            return dp[i][j]=1+lcs(a,b,i-1,j-1);
        else
            return dp[i][j]=0+max(lcs(a,b,i-1,j),lcs(a,b,i,j-1));
    }
    int lcs1(string a,string b){
        vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,-1));

        // if(i<0 || j<0)       since we dont have base case with 0 so we shifted the dp size
        //     return 0;
        for(int i=0;i<a.size()+1;i++)
            dp[i][0]=0;
        for(int j=0;j<b.size()+1;j++)
            dp[0][j]=0;
        
        for(int i=1;i<a.size()+1;i++){
            for(int j=1;j<b.size()+1;j++){
                if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[a.size()][b.size()];
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size(),vector<int>(text2.size(),-1));
        // return lcs(text1,text2,text1.size()-1,text2.size()-1);
        return lcs1(text1,text2);
    }
};