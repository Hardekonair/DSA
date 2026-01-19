class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thre) {
        vector<vector<int>> dist(n,vector<int>(n,1e8));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(auto it:edges){
            int u=it[0],v=it[1],w=it[2];
            dist[u][v]=w;
            dist[v][u]=w;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=1e8 && dist[k][j]!=1e8)
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int mini=n+1;
        int ans=0;
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<n;j++){
                if(i!=j && dist[i][j]<=thre)
                    temp++;
            }
            if(temp<=mini){
                mini=temp;
                ans=i;
            }
        }
        return ans;
    }
};