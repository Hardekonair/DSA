class Solution {
public:
    void lcpn(int i,string& temp,vector<string>& ans,string& dig,unordered_map<int,string>& mpp){
        if(i==dig.size()){
            ans.push_back(temp);
            return;
        }
        
        for(auto it:mpp[dig[i]-'0']){
            temp.push_back(it);
            lcpn(i+1,temp,ans,dig,mpp);
            temp.pop_back();
        }
    }

    void solve(int i,string dig,string& temp,vector<string>& ans,unordered_map<int,string>& mpp){
        if(i==dig.size()){
            ans.push_back(temp);
            return;
        }
        for(auto it:mpp[dig[i]-'0']){
            temp.push_back(it);
            solve(i+1,dig,temp,ans,mpp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string> mpp;
        vector<string> s={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int i=2;
        for(auto it:s){
            mpp[i++]=it;
        }
        string temp;
        vector<string>ans;
        // solve(0,digits,temp,ans,mpp);
        lcpn(0,temp,ans,digits,mpp);
        return ans;
    }
};