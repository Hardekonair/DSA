class Solution {
public:
    void dfs(string last,string start,vector<string>& path,unordered_map<string,int>& mpp,vector<vector<string>>& ans){
        if(last==start){
            vector<string>temp(path.begin(),path.end());
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            return;
        }
        int level=mpp[last];
        for(int i=0;i<last.size();i++){
            char prev=last[i];
            for(char c='a';c<='z';c++){
                if(c==prev) continue;
                last[i]=c;
                if(mpp.find(last)!=mpp.end() && mpp[last]==level-1){
                    path.push_back(last);
                    dfs(last,start,path,mpp,ans);
                    path.pop_back();
                }
            }
            last[i]=prev;
        }

    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        unordered_map<string,int>mpp;
        queue<string>q;
        q.push(beginWord);
        st.erase(beginWord);
        mpp[beginWord]=1;
        int sz=beginWord.size();
        while(!q.empty()){
            string word=q.front();
            int level=mpp[word];
            q.pop();
            if(word==endWord)   break;
            for(int i=0;i<sz;i++){
                char prev=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.count(word)){
                        q.push(word);
                        mpp[word]=level+1;
                        st.erase(word);
                    }
                }
                word[i]=prev;
            }
        }

        vector<vector<string>>ans;
        if(mpp.find(endWord)!=mpp.end()){
            vector<string>path;
            path.push_back(endWord);
            dfs(endWord,beginWord,path,mpp,ans);
        }
        return ans;
    }
};