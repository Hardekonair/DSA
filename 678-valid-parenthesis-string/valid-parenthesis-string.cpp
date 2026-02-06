class Solution {
public:
    vector<vector<int>>dp;
    bool valid(int i,int open,string s){
        if(open<0)
            return false;
        if(i==s.size()){
            if(open!=0)
                return false;
            return true;
        }
        if(dp[i][open]!=-1)
            return dp[i][open];
        if(s[i]=='(')
            return dp[i][open]=valid(i+1,open+1,s);
        else if(s[i]==')'){
            if(open==0)
                return false;
            return dp[i][open]=valid(i+1,open-1,s);}
        else 
            return dp[i][open]=valid(i+1,open+1,s) || valid(i+1,open,s) || valid(i+1,open-1,s);
        
    }
    bool checkValidString(string s) {
        int o=0;
        dp.resize(s.size(),vector<int>(s.size(),-1));
        return valid(0,o,s);
    }
};