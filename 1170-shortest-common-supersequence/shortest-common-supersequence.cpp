class Solution {
public:
    string lcs(string a,string b){
        vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,0));   // we do a.size()+1 to do 1 based indexing

        // first row and column will already be 0, no need of dp[0][i] = dp[i][0] = 0

        for(int i=1;i<a.size()+1;i++){
            for(int j=1;j<b.size()+1;j++){
                if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        string ans="";
        int i=a.size(),j=b.size();
        while(i>0 && j>0){
            if(a[i-1]==b[j-1]){
                ans+=a[i-1];
                i--;j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    ans+=a[i-1];
                    i--;
                }
                else{
                    ans+=b[j-1];
                    j--;
                }
            }
        }
        while(i>0){
            ans+=a[i-1];
            i--;
        }
        while(j>0){
            ans+=b[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        return lcs(str1,str2);
    }
};