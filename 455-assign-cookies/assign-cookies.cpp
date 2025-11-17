class Solution {
public:
    // int helper(vector<int>& g, vector<int>& s,int i,int j){
    //     if(j<0 || i<0){
    //         // if(c==g.size())
    //             return 1;
    //     }
        
    //     int notpick=helper(g,s,i-1,j);
    //     int pick=0;
    //     if(g[i]>=s[i]){
    //         pick=helper(g,s,i-1,j-1);
    //         // c++;
    //     }

    //     return max(pick);        
    // }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int c=0;
        int i=g.size()-1,j=s.size()-1;
        while(i>=0 && j>=0){
            if(g[i]<=s[j]){
                c++;
                j--;
            }
                i--;
        }
        return c;
    }
};