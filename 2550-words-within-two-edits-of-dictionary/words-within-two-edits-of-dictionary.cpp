class Solution {
public:
    int diff(string a,string b){
        int count=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])
                count++;
            if(count>2)
                return false;
        }
        return true;
    }
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        // unordered_set<string>q;
        // for(auto it:queries){
        //     q.insert(it);
        // }
        // for(auto it:dictionary){
        //     d.insert(it);
        // }
        vector<string>ans;
        for(auto it1:q){
            for(auto it2:d){
                if( diff(it1,it2) ){
                    ans.push_back(it1);
                    break;
                }
            }
        }
        return ans;
    }
};