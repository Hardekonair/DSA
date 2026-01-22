class Solution {
public:

    int find(int i,vector<int>& par){
        if(par[i]==i)
            return i;
        return par[i]=find(par[i],par);
    }

    void uni(int i,int j,vector<int>& par){
        int pari=find(i,par);
        int parj=find(j,par);
        if(pari==parj)  
            return;
        par[pari]=parj;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n=acc.size();
        unordered_map<string,int> mpp;

        vector<int>par(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }

        for(int i=0;i<n;i++){
            for(int j=1;j<acc[i].size();j++){
                if(mpp.find(acc[i][j])==mpp.end()){
                    mpp[acc[i][j]]=i;
                }
                else{
                    uni(i,mpp[acc[i][j]], par);
                }
            }
        }
        vector<vector<string>> vec(n);
        for(auto it:mpp){
            int i=find(it.second,par);
            vec[i].push_back(it.first);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(vec[i].size()==0)
                continue;
            
            sort(vec[i].begin(),vec[i].end());
            vector<string>temp;
            temp.push_back(acc[i][0]);
            for(auto it:vec[i]) 
                temp.push_back(it);
            
            ans.push_back(temp);
        }

        return ans;
    }
};