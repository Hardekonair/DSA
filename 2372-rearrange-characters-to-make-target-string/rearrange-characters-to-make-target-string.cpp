class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> t(26,0),st(26,0);
        for(auto it:target){
            t[it-'a']++;
        }
        for(auto it:s){
            st[it-'a']++;
        }

        int ans=1e9;
        for(int i=0;i<26;i++){
            if(t[i]>0){
                ans=min(ans,st[i]/t[i]);
            }
        }

        return ans;
    }
};