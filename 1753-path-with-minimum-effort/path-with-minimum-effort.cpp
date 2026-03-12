class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();

        priority_queue<pair<int,pair<int,int>>,
                            vector<pair<int,pair<int,int>>>,
                            greater<pair<int,pair<int,int>>>
                        >pq;

        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=0;

        pq.push({0,{0,0}});
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        while(!pq.empty()){
            auto [e,pos]=pq.top();
            auto [i,j]=pos;
            pq.pop();

            if(i==n-1 && j==m-1)
                return e;

            for(auto it:dir){
                int ni=i+it[0], nj=j+it[1];
                if(ni>=0 && ni<n && nj>=0 && nj<m){
                    int eff=abs(heights[i][j]-heights[ni][nj]);
                    int neff=max(eff,e);
                    if(neff<dis[ni][nj]){
                        pq.push({max(e,eff),{ni,nj}});
                        dis[ni][nj]=neff;
                    }
                }
            }

        }
        return -1;
    }
};