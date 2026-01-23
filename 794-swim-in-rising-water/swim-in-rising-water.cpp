class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // SINCE STARTING AND ENDING POINT IS FIXED WE USE
        // SINGLE SOURCE SHORTEST PATH
        // DJIKSTRA ALGORITHM
        
        int n=grid.size();

        vector<vector<int>> res(n,vector<int>(n,1e9));

        priority_queue<pair<int,pair<int,int>>,         // {time,i,j}
                            vector<pair<int,pair<int,int>>>,
                            greater<pair<int,pair<int,int>>>
                           > pq;

        pq.push({grid[0][0],{0,0}});
        res[0][0]=grid[0][0];
        vector<vector<int>> d={{1,0},{0,1},{-1,0},{0,-1}};
        while(!pq.empty()){
            int t=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            
            if(r==n-1 && c==n-1)    
                return t;

            if(t>res[r][c])
                continue;

            for(int i=0;i<4;i++){
                int nr=r+d[i][0], nc=c+d[i][1];
                if(nr<n && nc<n && nr>=0 && nc>=0){
                    int nt=max(grid[nr][nc],t);
                    if(nt<res[nr][nc]){
                        res[nr][nc]=nt;
                        pq.push({nt,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};