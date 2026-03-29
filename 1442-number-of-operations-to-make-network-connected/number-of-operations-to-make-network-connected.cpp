class Solution {
public:
    class DSU{
        private:
            vector<int>parent,rank;
        public:
            DSU(int n){
                parent.resize(n);
                rank.resize(n,0);

                for(int i=0;i<n;i++){
                    parent[i]=i;
                }
            }

            int find(int x){
                if(parent[x]==x)    return x;
                return parent[x]=find(parent[x]);
            }

            void uni(int u,int v){
                int pu=find(u);
                int pv=find(v);

                if(rank[pu]>rank[pv])
                    parent[pv]=pu;                
                else if(rank[pv]>rank[pu])
                    parent[pu]=pv;
                else 
                    parent[pu]=pv;
                    rank[pv]+=1;
            }
    };
    int makeConnected(int n, vector<vector<int>>& conn) {

        DSU dsu(n);

        int extraedge=0;
        for(auto it:conn){
            int paru=dsu.find(it[0]),parv=dsu.find(it[1]);
            if(paru==parv)  extraedge++;
            else    dsu.uni(paru,parv);
        }

        int component=0;
        for(int i=0;i<n;i++){
            if(dsu.find(i)==i)
                component++;
        }

        if(conn.size()<n-1)
            return -1;
        return component-1;
    }
    // void dfs(int i,vector<vector<int>>& adj, vector<int>& vis){
    //     vis[i]=1;
    //     for(auto it:adj[i]){
    //         if(vis[it]==0){
    //             dfs(it,adj,vis);
    //         }
    //     }
    // }
    // int makeConnected(int n, vector<vector<int>>& conn) {
    //     vector<vector<int>>adj(n);
    //     for(auto it:conn){
    //         adj[it[0]].push_back(it[1]);
    //         adj[it[1]].push_back(it[0]);
    //     }

    //     int c=0;
    //     vector<int>vis(n,0);
    //     for(int i=0;i<n;i++){
    //         if(vis[i]==0){
    //             dfs(i,adj,vis);
    //             c++;
    //         }
    //     }

    //     if(conn.size()<n-1) return -1;
    //     return c-1;
    // }
};