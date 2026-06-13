class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto it:words){
            int wt=0;
            for(auto letter:it){
                wt+=weights[letter-'a'];
            }
            wt%=26;
            ans+='z'-wt;
        }
        return ans;
    }
};