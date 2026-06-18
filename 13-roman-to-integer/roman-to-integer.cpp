class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        unordered_map<char,int>mpp{
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},

        };
        int ans=0;
        for(int i=0;i<n;i++){
            if(i+1<s.size() && mpp[s[i]]<mpp[s[i+1]] ){
                ans=ans-mpp[s[i]];
            }
            else{
                ans=ans+mpp[s[i]];
            }
        }
        return ans;
    }
};