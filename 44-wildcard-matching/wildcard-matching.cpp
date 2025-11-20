class Solution {
public:
    vector<vector<int>>dp;
    bool match(string a,string b,int i,int j){
        if(i<0 && j<0)
            return true;
        if(i<0 and j>=0)
            return false;
        if(j<0){
            for(int k=0;k<=i;k++){
                if(a[k]!='*')
                    return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];

        if(a[i]==b[j] || a[i]=='?')
            return dp[i][j]=match(a,b,i-1,j-1);
        else if(a[i]=='*'){
            return dp[i][j]=(match(a,b,i-1,j) || match(a,b,i,j-1));
        }
        return dp[i][j]=false;
    }

    bool match1(string a,string b){
        vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1,0));

        // if(i<0 && j<0)
        //     return true;
        dp[0][0]=1;

        // if(i<0 and j>=0)
        //     return false;        // NO NEED TO REINITIALISE ALREADY 0

        // if(j<0){
        //     for(int k=0;k<=i;k++){
        //         if(a[k]!='*')
        //             return false;
        //     }
        //     return true;
        // }
        for(int i=1;i<a.size()+1;i++){
            bool flag=true;
            for(int ii=1;ii<=i;ii++){
                if(a[ii-1]!='*'){     
                    flag=false;
                    break;
                }
            }
            if(flag)
                dp[i][0]=1;
        }

        for(int i=1;i<a.size()+1;i++){
            for(int j=1;j<b.size()+1;j++){
                if(a[i-1]==b[j-1] || a[i-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(a[i-1]=='*')
                    dp[i][j]=(dp[i-1][j] || dp[i][j-1]);
                else
                    dp[i][j]=0;
            }
        }
        return dp[a.size()][b.size()];
    }
    bool isMatch(string s, string p) {
        dp.resize(p.size(),vector<int>(s.size(),-1));
        // return match(p,s,p.size()-1,s.size()-1);
        return match1(p,s);
    }
};