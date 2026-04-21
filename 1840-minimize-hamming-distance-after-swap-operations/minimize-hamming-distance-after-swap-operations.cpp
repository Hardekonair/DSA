class DSU{
    public:
        // int n;
        vector<int>rank;
        vector<int>parent;

        DSU(int n){
            // this->n=n;
            rank.resize(n,0);
            for(int i=0;i<n;i++){
                parent.push_back(i);
            }
        }

        int find(int x){
            if(parent[x]==x)
                return x;
            return parent[x]=find(parent[x]);
        }

        void uni(int a,int b){
            int para=find(a);
            int parb=find(b);
            if(para==parb)  return;
            else if(rank[para]>rank[parb]){
                parent[parb]=para;
            }
            else if(rank[para]<rank[parb]){
                parent[para]=parb;
            }
            else{
                parent[parb]=para;
                rank[para]++;
            }
        }
};
    
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        DSU dsu(n);
        
        for(auto it:allowedSwaps){
            dsu.uni(it[0],it[1]);
        }

        unordered_map<int,unordered_map<int,int>>mpp;
        for(int i=0;i<n;i++){
            int x=dsu.find(i);
            mpp[x][source[i]]++;
        }

        int ans=0;
        for(int i=0;i<n;i++){
            int p=dsu.find(i);
            if(mpp[p][target[i]]>0){
                mpp[p][target[i]]--;
            }
            else
                ans++;
        }
        return ans;
    }
};