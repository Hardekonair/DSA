class Solution {
public:
    void dfs(int i,vector<vector<int>>& isConnected,vector<int>&vis){
        vis[i]=1;
        for(int j=0;j<vis.size();j++){
            if(isConnected[i][j]==1 && !vis[j]){
                dfs(j,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int provinces=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,isConnected,vis);
                provinces++;
            }
        }
        return provinces;
    }
};