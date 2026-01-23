class Solution {
public:
    void dfs(int node,int parent,vector<int>& in,vector<int>& low,vector<vector<int>>& bridges, vector<int>& vis, vector<vector<int>>& adj,int& timer){
        vis[node]=1;
        low[node]=in[node]=timer;
        for(auto it:adj[node]){
            if(it==parent)
                continue;
            if(vis[it])
                low[node]=min(low[node],low[it]);
            if(vis[it]==0){
                timer++;
                dfs(it,node,in,low,bridges,vis,adj,timer);
                timer--;
                low[node]=min(low[node],low[it]);
                if(in[node]<low[it]){
                    bridges.push_back({node,it});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<vector<int>>adj(n);
        for(auto it:con){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int timer=0;
        vector<int> in(n),low(n),vis(n,0);
        vector<vector<int>>bridges;

        dfs(0,-1,in,low, bridges,vis,adj,timer);
        return bridges;
    }
};