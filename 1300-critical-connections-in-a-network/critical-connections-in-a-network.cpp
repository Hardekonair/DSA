class Solution {
public:
    int timer=1;
    vector<vector<int>>bridges;
    void dfs(int node, int parent, vector<int>& low,vector<int>& tin,vector<int>& par,vector<int>& vis,vector<vector<int>>& adj){
        vis[node]=1;
        low[node]=tin[node]=timer++;

        for(auto it:adj[node]){
            if(it==parent) continue;
            else if(vis[it]==0){
                dfs(it,node,low,tin,par,vis,adj);
                low[node]=min(low[it],low[node]);

                if(tin[node]<low[it]){
                    bridges.push_back({node,it});
                }               
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

        }
        vector<int>vis(n,0),par(n,-1),low(n,-1),tin(n,-1);


        for(int i=0;i<n;i++){
            if(par[i]==-1){
                dfs(i,i,low,tin,par,vis,adj);
            }
        }
        return bridges;
    }
};