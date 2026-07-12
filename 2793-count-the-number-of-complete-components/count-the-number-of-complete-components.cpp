class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int& nodes, int& degreesum){
        vis[node]=1;
        for(auto it:adj[node]){
            degreesum++;
            if(vis[it]==0){
                dfs(it,adj,vis,nodes,degreesum);
            }
        }
        // degreesum+=adj[node].size();
        nodes++;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto it:edges){
            int a=it[0], b=it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int>vis(n,0);
        int ans=0;

        for(int i=0;i<n;i++){
            int nodes=0, degreesum=0;
            if(vis[i]==0){
                dfs(i,adj,vis,nodes,degreesum);
            }

            int edges=degreesum/2;
            int idealEdges = nodes*(nodes-1)/2;

            if(edges==idealEdges && nodes!=0)
                ans++;
        }

        return ans;

    }
};