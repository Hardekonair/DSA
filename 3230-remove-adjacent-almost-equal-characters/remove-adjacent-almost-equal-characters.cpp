class Solution {
public:
    bool isadj(char a,char b){
        // if(abs(a-b)<=1) 
        //     return true;
        // return false;

        return (abs(a-b)<=1);
    }
    int removeAlmostEqualCharacters(string word) {
        int ans=0;
        int n=word.size();
        for(int i=1;i<n;i++){
            if(isadj(word[i-1],word[i])){
                ans++;
                i++;
            }
        }
        return ans;
    }
};