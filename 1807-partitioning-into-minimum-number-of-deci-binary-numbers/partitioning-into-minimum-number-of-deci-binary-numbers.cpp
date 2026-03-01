class Solution {
public:

    int fn(string n){
        if(n==""){
            return 0;
        }
        string temp="";
        for(int i=0;i<n.size();i++){
            if(n[i]=='0')
                temp.push_back('0');
            else
                temp.push_back('1');
        }
        string ans="";
        for(int i=0;i<n.size();i++){
            int ch=(n[i]-'0')-(temp[i]-'0');

            if(ch==0 && ans.empty())  continue;
            ans.push_back(ch+'0');
        }
        return 1+fn(ans);
    }

    int minPartitions(string n) {
        // return fn(n);
        int dig=0;
        for(auto it:n){
            dig=max(dig,it-'0');
        }
        return dig;
    }
};