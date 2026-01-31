class Solution {
public:
    bool ispalin(string s){
        string s1=s;
        reverse(s1.begin(),s1.end());
        return s1==s;
    }

    void pp(int i,string s,vector<string>& temp,vector<vector<string>>& ans){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<s.size();j++){
            string raw=s.substr(i,j-i+1);
            if(ispalin(raw)){
                temp.push_back(raw);
                pp(j+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }

    void solve(string s,vector<string>& part,vector<vector<string>>& ans){
        if(s.size()==0){
            ans.push_back(part);
            return;
        }
        for(int i=0;i<s.size();i++){
            string temp=s.substr(0,i+1);
            if(ispalin(temp)){
                part.push_back(temp);
                solve(s.substr(i+1),part,ans);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>part;
        vector<vector<string>> ans;
        // solve(s,part,ans);
        pp(0,s,part,ans);
        return ans;
        
    }
};