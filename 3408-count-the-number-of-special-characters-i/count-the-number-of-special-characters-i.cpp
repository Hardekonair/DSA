class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>vec(100,0);
        for(auto it:word){
            vec[it-'A']++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(vec[i]!=0 && vec[i+32]!=0)
                ans++;
        }
        return ans;
    }
};