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
                // if(isvalid(word,endWord) && mpp.find(endWord)!=mpp.end()){
                //     found=true;
                //     break;
                // }
                for(auto it:mpp){
                    if(isvalid(word,it.first) && it.second==0){
                        if(it.first==endWord){
                            return len+1;
                        }
                        q.push(it.first);
                        mpp[it.first]=1;
                    }
                }
            }
            len++;
        }
        if(!found)  return 0;
        return len-1;
    }
};