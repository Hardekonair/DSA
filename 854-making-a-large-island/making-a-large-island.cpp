class Solution {
public:
    class DSU {
        public:
            vector<int>parent,rank;
            DSU(int n){
                rank.resize(n,0);
                parent.resize(n);
                for(int i=0;i<n;i++){
                    parent[i]=i;
                }
            }

            int find(int x){
                if(parent[x]==x)
                    return x;
                return parent[x]=find(parent[x]);
            }

            void uni(int a,int b){
                int para=find(a),parb=find(b);
                if(para==parb)  
                    return;

                if(rank[para]>rank[parb])   
                    parent[parb]=para;
                else if(rank[para]<rank[parb])  
                    parent[para]=parb;
                else{
                    parent[parb]=para;
                    rank[para]++;
                }
            }
    };

    vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(int i,int j,int n,vector<vector<int>>& grid,vector<vector<int>>& vis,DSU& dsu){
        vis[i][j]=1;
        for(auto &it:dir){
            int ni=i+it[0],nj=j+it[1];
            bool inside=(ni<n && nj<n && ni>=0 && nj>=0);
            if(inside && grid[ni][nj]==1 && vis[ni][nj]==0){
                dsu.uni(i*n+j,ni*n+nj);
                dfs(ni,nj,n,grid,vis,dsu);
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        DSU dsu(n*n);


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    dfs(i,j,n,grid,vis,dsu);
                }
            }
        }
        int maxarea=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    mpp[dsu.find(i*n+j)]++;
                    maxarea=max(maxarea,mpp[dsu.find(i*n+j)]);
                }
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int temp=0;
                    unordered_set<int>st;
                    for(auto it:dir){
                        int ni=i+it[0],nj=j+it[1];
                        bool inside=(ni<n && nj<n && ni>=0 && nj>=0);
                        if(inside && grid[ni][nj]==1 && st.count(dsu.find(ni*n+nj))==0){
                                st.insert(dsu.find(ni*n+nj));
                                temp+=mpp[dsu.find(ni*n+nj)];
                            
                        }
                    }
                    maxarea=max(maxarea,1+temp);
                }
            }
        }
        return maxarea;
    }
    // bool isvalid(int r,int c,int n){
    //     return r>=0 && c>=0 && r<n && c<n;
    // }

    // int find(int i,vector<int>& par){
    //     if(par[i]==i)
    //         return i;
    //     return par[i]=find(par[i],par);
    // }

    // void uni(int i,int j,vector<int>& par,vector<int>& size){
    //     int pari=find(i,par);
    //     int parj=find(j,par);
    //     if(pari==parj)
    //         return ;
    //     if(size[pari]<size[parj]){
    //         par[pari]=parj;
    //         size[parj]+=size[pari];
    //     }
    //     else{
    //         par[parj]=pari;
    //         size[pari]+=size[parj];
    //     }
    // }
    // int largestIsland(vector<vector<int>>& grid) {
    //     int n=grid.size();
        
    //     vector<int> par(n*n),size(n*n,1);
    //     for(int i=0;i<n*n;i++){
    //         par[i]=i;
    //     }

    //     vector<vector<int>> d={{0,-1},{-1,0},{0,1},{1,0}};
    //     for(int r=0;r<n;r++){
    //         for(int c=0;c<n;c++){
    //         if(grid[r][c]){
    //             // vis[r][c]=1;
    //             for(auto &ti:d){
    //                 int nr=r+ti[0],nc=c+ti[1];
    //                 if(isvalid(nr,nc,n)){
    //                     if(grid[nr][nc]){
    //                         int n1=r*n+c,n2=nr*n+nc;
    //                         if(find(n1,par)!=find(n2,par)){
    //                             uni(n1,n2,par,size);
    //                         }
    //                     }
    //                 }
    //             }
    //         }

    //         }
    //     }

    //     int ans=0;
    //     for(int i=0;i<n*n;i++){
    //         if(par[i]==i)
    //             ans=max(ans,size[i]);
    //     }

    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             if(grid[i][j]==0){
    //                 unordered_set<int>st;
    //                 for(auto it:d){
    //                     int nr=i+it[0],nc=j+it[1];
    //                     if(isvalid(nr,nc,n)){
    //                         if(grid[nr][nc]){
    //                             st.insert(find(nr*n+nc,par));
    //                         }
    //                     }
    //                 }
    //                 int temp=0;
    //                 for(auto &it:st)
    //                     temp+=size[it];
    //                 ans=max(ans,temp+1);
    //             }
    //         }
    //     }
    //     return ans;
    // }
};