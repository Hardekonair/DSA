class Solution {
public:
    int lcs(string a,string b){
        vector<int> prev(a.size()+1,0),curr(b.size()+1,0);
        for(int i=1;i<a.size()+1;i++){
            for(int j=1;j<b.size()+1;j++){
                if(a[i-1]==b[j-1])
                    curr[j]=1+prev[j-1];
                else
                    curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return curr[a.size()];
    }
    int minInsertions(string s) {
        string a=s;
        reverse(a.begin(),a.end());
        int c=lcs(s,a);
        return s.size()-c;
    }
};