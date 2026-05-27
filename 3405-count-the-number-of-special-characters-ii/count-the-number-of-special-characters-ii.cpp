class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        vector<int>lower(26,0);
        vector<int>upper(26,0);

        for(auto it:word){
            if(isupper(it)){
                // if(lower[it-'A']!=0){
                //     upper[it-'A']++;
                // }
                // else{
                //     lower[it-'A']=-1;
                //     upper[it-'A']=-1;
                // }
                upper[it-'A']++;
            }
            else if(islower(it) && lower[it-'a']!=-1){
                if(upper[it-'a']>0)
                    lower[it-'a']=-1;
                else
                    lower[it-'a']++;
            }
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(lower[i]>0 && upper[i]>0){
                ans++;
            }
        }
        return ans;
    }
};