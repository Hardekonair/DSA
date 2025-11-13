class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int i=0;
        int n=s.size();
        while(i<n){
            if(!st.empty() && st.top().first==s[i]){
                int x=st.top().second;
                if(x==k-1){
                    while(x){
                        st.pop();
                        x--;
                    }
                }
                else
                    st.push({s[i],x+1});
            }
            else{
                int c=1;
                st.push({s[i],c});
            }
            i++;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};