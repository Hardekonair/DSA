class Solution {
public:
    const int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue< pair<long long,long long>,
                        vector<pair<long long,long long>>,
                        greater<pair<long long,long long>>
                    > q;
        q.push({0,0});
        int count=0;
        vector<long long>dis(n,LLONG_MAX);
        dis[0]=0;
        vector<int>ways(n,0);
        ways[0]=1;

        while(!q.empty()){
            // int d=q.top().first;
            // int node=q.top().second;
            auto [d,node]=q.top();
            q.pop();
            if(dis[node]<d)
                continue;
            for(auto it:adj[node]){
                if(dis[it.first]==d+it.second){
                    ways[it.first]=(ways[it.first]+ways[node]) % mod;
                }
                else if(dis[it.first]>d+it.second){
                    dis[it.first]=d+it.second;
                    ways[it.first]=ways[node];
                    q.push({dis[it.first],it.first});
                }
            }
        }
        return ways[n-1];
    }
};