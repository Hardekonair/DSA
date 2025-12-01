class Solution {
public:
    int ladderLength(string sw, string ew, vector<string>& word) {
        queue<pair<string,int>> q;
        q.push({sw,1});
        
        unordered_set<string> st(word.begin(),word.end());
        st.erase(sw);
        while(!q.empty()){
            string w=q.front().first;
            int step=q.front().second;
            q.pop();
            if(w==ew)
                return step;
            for(int i=0;i<w.size();i++){
                char org=w[i];
                for(char it='a';it<='z';it++){
                    w[i]=it;
                    if(st.find(w)!=st.end()){
                        q.push({w,step+1});
                        st.erase(w);
                    }

                }
                w[i]=org;
            }
        }
        return 0;
    }
};