class Solution {
public:
    bool isvalid(int r,int c,int n){
        return r>=0 && c>=0 && r<n && c<n;
    }

    int find(int i,vector<int>& par){
        if(par[i]==i)
            return i;
        return par[i]=find(par[i],par);
    }

    void uni(int i,int j,vector<int>& par,vector<int>& size){
        int pari=find(i,par);
        int parj=find(j,par);
        if(pari==parj)
            return ;
        if(size[pari]<size[parj]){
            par[pari]=parj;
            size[parj]+=size[pari];
        }
        else{
            par[parj]=pari;
            size[pari]+=size[parj];
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));

        vector<int> par(n*n),size(n*n,1);
        for(int i=0;i<n*n;i++){
            par[i]=i;
        }

        vector<vector<int>> d={{0,-1},{-1,0},{0,1},{1,0}};
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
            if(grid[r][c]){
                // vis[r][c]=1;
                for(auto ti:d){
                    int nr=r+ti[0],nc=c+ti[1];
                    if(isvalid(nr,nc,n)){
                        if(grid[nr][nc]){
                            int n1=r*n+c,n2=nr*n+nc;
                            if(find(n1,par)!=find(n2,par)){
                                uni(n1,n2,par,size);
                            }
                        }
                    }
                }
            }

            }
        }

        int ans=0;
        for(int i=0;i<n*n;i++){
            if(par[i]==i)
                ans=max(ans,size[i]);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int>st;
                    for(auto it:d){
                        int nr=i+it[0],nc=j+it[1];
                        if(isvalid(nr,nc,n)){
                            if(grid[nr][nc]){
                                st.insert(find(nr*n+nc,par));
                            }
                        }
                    }
                    int temp=0;
                    for(auto it:st)
                        temp+=size[it];
                    ans=max(ans,temp+1);
                }
            }
        }
        return ans;
    }
};