class Solution {
public:
    int minimumDeletions(string s) {   //     DP APPROACH
        int deletions=0,bcount=0;
        for(auto it:s){
            if(it=='b')
                bcount++;
            else
                deletions=min(bcount,deletions+1);
        }
        return deletions;
    }
    // int minimumDeletions(string s) {
    //     int n=s.size();
    //     stack<int> st;
    //     int count=0;
    //     for(int i=0;i<n;i++){
    //         if(!st.empty() && st.top()=='b' && s[i]=='a'){
    //             st.pop();
    //         count++;}
    //         else
    //         st.push(s[i]);
    //     }
    //     return count;
    // }
};