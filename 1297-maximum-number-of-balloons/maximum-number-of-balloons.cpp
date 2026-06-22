class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mpp;
        mpp['b']=0;
        mpp['a']=0;
        mpp['l']=0;
        mpp['o']=0;
        mpp['n']=0;

        for(auto it:text){
            if(mpp.find(it)!=mpp.end()){
                mpp[it]++;
            }
        }

        int ans=1e9;
        for(auto it:mpp){
            if(it.first=='l' || it.first=='o')
            ans=min(ans,it.second/2);
            else
            ans=min(ans,it.second);
        }
        return ans;

    }
};