class Solution {
public:
    vector<int>dp;
    // bool ansbreak1(int i,string s,unordered_set<string>& mpp){
    //     if(i<0){
    //         return true;
    //     }
    //     if(dp[i]!=-1)
    //         return dp[i];
    //     for(int k=i;k>=0;k--){
    //         string temp=s.substr(k,i-k+1);
    //         if(mpp.find(temp)!= mpp.end() && ansbreak1(k-1,s,mpp)){
    //             return dp[i]=true;
    //         }
    //     }
    //     return dp[i]=false;
    // }
    bool ansbreak(int i,string s,unordered_set<string>& mpp){
        if(i==s.size()){
            return true;;
        }
        if(dp[i]!=-1)
            return dp[i];
        string temp="";
        for(int k=i;k<s.size();k++){
            // string temp=s.substr(i,k-i+1);
            temp+=s[k];
            if(mpp.find(temp)!= mpp.end() && ansbreak(k+1,s,mpp)){
                return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool solve(int ind,int n,string s,unordered_set<string> st){
        if(ind==n)
            return true;
        if(st.find(s)!=st.end())
            return true;
        for(int i=1;i<n;i++){
            string temp=s.substr(ind,i);
            if(st.find(temp)!=st.end() && solve(ind+i,n,s,st))
                return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        int n=s.size();
        dp.resize(n,-1);
        // return ansbreak1(n-1,s,st);
        return ansbreak(0,s,st);
        
    }
};