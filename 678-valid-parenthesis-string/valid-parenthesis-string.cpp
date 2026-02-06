class Solution {
public:
    vector<vector<int>>dp;
    bool valid(int i,int close,string s){
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
    bool checkValidString(string s) {
        int o=0;
        dp.resize(s.size(),vector<int>(s.size(),-1));
        return valid(s.size()-1,o,s);
    }
};