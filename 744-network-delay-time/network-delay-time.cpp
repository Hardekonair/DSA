class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        priority_queue< pair<int,int>,
                        vector<pair<int,int>>,
                        greater<pair<int,int>>
                    > q;
        q.push({0,k});
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        dis[0]=0;

        while(!q.empty()){
            int node=q.top().second;
            int d=q.top().first;
            q.pop();
            if(dis[node]<d)
                continue;
            for(auto it:adj[node]){
                if(dis[it.first]>d+it.second){
                    dis[it.first]=d+it.second;
                    q.push({dis[it.first],it.first});
                }
            }
        }
        int maxi=-1;
        for(auto it:dis){
            if(it>maxi)
                maxi=it;
        }
        return maxi==INT_MAX?-1:maxi;
    }
};