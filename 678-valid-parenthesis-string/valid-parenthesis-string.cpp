class Solution {
public:
    vector<vector<int>>dp;
    bool valid(int i,int close,string& s){
        if(close<0)
            return false;
        if(i==0){
            if((s[i]=='(' && close==1) || (s[i]=='*' && close<=1))
                return true;
            return false;
        }
        if(dp[i][close]!=-1)
            return dp[i][close];
        if(s[i]=='('){
            if(close==0)
                return false;
            return dp[i][close]=valid(i-1,close-1,s);
        }
        else if(s[i]==')')
            return dp[i][close]=valid(i-1,close+1,s);
        else 
            return dp[i][close]=valid(i-1,close+1,s) || valid(i-1,close,s) || valid(i-1,close-1,s);
        
    }
    bool valid1(string& s){
        int n=s.size();
        vector<vector<int>>dp(s.size(),vector<int>(s.size()+1,0));
        // if(close<0)
        //     return false;
        // if(i==0){
        //     if((s[i]=='(' && close==1) || (s[i]=='*' && close<=1))
        //         return true;
        //     return false;
        // }
        if(s[0]=='(') 
            dp[0][1]=1;
        if (s[0]=='*'){
            dp[0][1]=dp[0][0]=1;
        }

        for(int i=1;i<n;i++){                 // since valid start from n-1 in memo
            for(int close=0;close<n;close++){
                if(s[i]=='('){
                    if(close>0)
                        dp[i][close]=dp[i-1][close-1];
                }
                else if(s[i]==')')
                    dp[i][close]=dp[i-1][close+1];
                else 
                    dp[i][close]=dp[i-1][close+1] || dp[i-1][close] || (close>0?dp[i-1][close-1]:0);
            }
        }
        return dp[n-1][0];        
    }
    bool checkValidString(string s) {
        int o=0;
        dp.resize(s.size(),vector<int>(s.size(),-1));
        // return valid(s.size()-1,o,s);
        return valid1(s);
    }
};