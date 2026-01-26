class Solution {
public:
    void solve(int open,int close,int n,string temp,vector<string> &ans){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }

        if(open<n){
            temp.push_back('(');
            solve(open+1,close,n,temp,ans);
            temp.pop_back();
        }
        if(close<open){
            temp.push_back(')');
            solve(open,close+1,n,temp,ans);
            temp.pop_back();
        }
    }
    void fn(string s,vector<string>& ans,int n,int open){
        if(s.size()==2*n){
            if(open==0)
            ans.push_back(s);
            return;
        }
        if(open<n){
            fn(s+'(',ans,n,open+1);
        }
        if(open>0){
            fn(s+')',ans,n,open-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp="";
        vector<string> ans;
        solve(0,0,n,temp,ans);
        // fn(temp,ans,n,0);
        return ans;

        
    }
};