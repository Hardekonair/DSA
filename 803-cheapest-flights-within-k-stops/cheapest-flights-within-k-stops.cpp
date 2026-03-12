class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int>p(n,1e9);
        p[src]=0;
        queue<tuple<int,int,int>>q;
        q.push({0,src,-1});          
        while(!q.empty()){
            auto[price,node,stop]=q.front();
            q.pop();

            if(stop>k) continue;

            for(auto it:adj[node]){
                if(p[it[0]]>price+it[1] && stop+1<=k){
                    q.push({price+it[1],it[0],stop+1});
                    p[it[0]]=price+it[1];
                }
            }
        }
        return p[dst]==1e9?-1:p[dst];
    }   
    // int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //     vector<vector<pair<int,int>>> adj(n);
    //     for(auto it:flights){
    //         adj[it[0]].push_back({it[1],it[2]});
    //     }

    //     queue<pair<int,pair<int,int>>> q;
    //     q.push({-1,{src,0}});
    //     vector<int> dis(n,INT_MAX);
    //     dis[src]=0;

    //     while(!q.empty()){
    //         int stop=q.front().first;
    //         int node=q.front().second.first;
    //         int cost=q.front().second.second;
    //         q.pop();
    //         if((stop == k && node==dst) || (stop==k && node!=dst))
    //             continue;
    //         for(auto it:adj[node]){
    //             if(dis[it.first]>cost+it.second){
    //                 dis[it.first]=cost+it.second;
    //                 q.push({stop+1,{it.first,dis[it.first]}});
    //             }
    //         }
    //     }
    //     return dis[dst]==INT_MAX?-1:dis[dst];
    // }
};