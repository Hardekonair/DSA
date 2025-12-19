class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size(),m=h[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0]=0;
        priority_queue<
                        pair<int,pair<int,int>>,
                        vector<pair<int,pair<int,int>>>,
                        greater<pair<int,pair<int,int>>>
                    > q;
        q.push({0,{0,0}});

        vector<int> r={0,-1,0,1};
        vector<int> c={-1,0,1,0};
        int ans=INT_MAX;
        
        while(!q.empty()){
            int d=q.top().first;
            int x=q.top().second.first;
            int y=q.top().second.second;
            q.pop();

            if(x==n-1 && y==m-1)
                return d;
                
            else{
            for(int i=0;i<4;i++){
                int nr=x+r[i], nc=y+c[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int newd=max(d,abs(h[x][y]-h[nr][nc]));
                    if(newd<dis[nr][nc]){
                        q.push({newd,{nr,nc}});
                        dis[nr][nc]=newd;
                    }
                }
                
            }
            } 
        }
        return -1;
    }
};