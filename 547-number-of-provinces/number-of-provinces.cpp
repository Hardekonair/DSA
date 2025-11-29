class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0)
                dfs(it,adj,vis);
        }

    }
    int findCircleNum(vector<vector<int>>& iscon) {
        int n=iscon.size();

        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(iscon[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }


        int c=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                c++;
                dfs(i,adj,vis);
            }
        }
        return c;
    }
};