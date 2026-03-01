class Solution {
public:
    bool isvalid(string a,string b){
        if(a.size()!=b.size() || a==b)  
            return false;
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])
                cnt++;
        }
        return cnt==1?true:false;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_map<string,int>mpp;
        for(auto it:wordList){
            mpp[it]=0;
        }
        q.push(beginWord);

        int len=1;
        bool found=false;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                string word=q.front();
                q.pop();
                if(word==endWord){
                    return len;
                }
                for(int i=0;i<word.size();i++){
                    char prev=word[i];
                    for(char ch='a';ch<='z';ch++){
                        word[i]=ch;
                        if(mpp.find(word)!=mpp.end() && mpp[word]==0){
                            q.push(word);
                            mpp[word]=1;
                        }
                        
                    }
                    word[i]=prev;
                }
            }
            len++;
        }
        return 0;
    }
};