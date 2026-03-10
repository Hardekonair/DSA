class Solution {
public:         
                                            // DFS APPROACH
    bool dfs(int i,int c,vector<int>& color,vector<vector<int>>& graph){
        color[i]=c;
        for(auto it:graph[i]){
            if(color[it]==color[i]) return false;
            else if(color[it]==-1){
                if(dfs(it,1-c,color,graph)==false)  
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1)
                if(dfs(i,0,color,graph)==false)
                    return false;
        }
        return true;
    }
                                            // BFS APPROACH
    // bool isBipartite(vector<vector<int>>& graph) {
    //     int n=graph.size();
    //     vector<int>color(n,-1);

    //     for(int i=0;i<n;i++){
    //         if(color[i]==-1){
    //             queue<int>q;
    //             q.push(i);
                
    //             while(!q.empty()){
    //                 int node=q.front();
    //                 q.pop();
    //                 for(auto it:graph[node]){
    //                     if(color[it]==-1){
    //                         color[it]=1-color[node];
    //                         q.push(it);
    //                     }
    //                     else if(color[it]==color[node]) 
    //                         return false;
    //                 }
    //             }
    //         }
    //     }
    //     return true;
    // }
};