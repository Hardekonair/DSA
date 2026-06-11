class Solution {
public:
    int dfs(int x, int parent,vector<vector<int>>& edges){
        
        int len=0;
        for(auto it:edges[x]){
            if(it==parent) continue;
            len=max(len,1+dfs(it,x,edges));
        }
        return len;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+2);

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int start=1;
        int maxlen=dfs(1,-1,adj);
        // return maxlen;

        long long ans = 1;
        for(int i = 1; i < maxlen; i++){
            ans = (ans * 2) % 1000000007;
        }
        return ans;
    }
};