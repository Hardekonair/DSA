class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size();
        char last=' ';
        int temp=0;
        for(auto it:word){
            if(last!=it){
                last=it;
            }
            else 
                temp++;
        }
        return temp+1;
    }
};