class Solution {
public:
    string processStr(string s) {
        string ans="";
        for(auto it:s){
            if(isalpha(it))
                ans+=it;
            else if(!ans.empty() && it=='*')
                ans.pop_back();
            else if(it=='#')
                ans=ans+ans;
            else if(it=='%')
                reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};