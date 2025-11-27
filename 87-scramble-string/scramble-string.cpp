class Solution {
public:
    unordered_map<string,bool> dp;

    bool fn(string s1,string s2){
        int n=s1.size();
        if(s1==s2)  
            return true;
        if(s1.size()!=s2.size())
            return false;
        if(dp.find(s1+" "+s2)!=dp.end())
            return dp[s1+" "+s2];
        // bool ans=false;
        for(int i=1;i<s1.size();i++){
            bool notswap=fn(s1.substr(0,i),s2.substr(0,i)) && fn(s1.substr(i,n-i),s2.substr(i,n-i));
            // WRONG
            // bool swap=fn(s1.substr(i,n-i),s2.substr(0,n-i)) && fn(s1.substr(0,i),s2.substr(n-i,i));
            bool swap=fn(s1.substr(0,i),s2.substr(n-i,i)) && fn(s1.substr(i),s2.substr(0,n-i));
            // ans=swap || notswap;
            if(swap || notswap)
                return dp[s1+" "+s2]=true;
        }
        return dp[s1+" "+s2]=false;
    }
    bool isScramble(string s1, string s2) {
        return fn(s1,s2);
    }
};