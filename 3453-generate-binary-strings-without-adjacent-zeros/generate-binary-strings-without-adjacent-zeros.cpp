class Solution {
public:
    void fn(string s,vector<string>& vec,int n){
        if(n==0){
            vec.push_back(s);
            return;
        }
        fn(s+'1',vec,n-1);
        if(s.empty() || s.back()!='0')
            fn(s+'0',vec,n-1);
    }
    vector<string> validStrings(int n) {
        vector<string> vec;
        string s="";
        fn(s,vec,n);
        return vec;
    }

};