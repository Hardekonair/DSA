class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                queue<int> q;
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(int i=0;i<graph[node].size();i++){
                        if(color[graph[node][i]]==-1){
                            q.push(graph[node][i]);
                            color[graph[node][i]]=color[node]?0:1;
                        }
                        else if(color[node]==color[graph[node][i]])
                            return false;
                    }
                }
                
            }
        }
        return true;
    }
};