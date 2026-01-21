class Solution {
public:
    // void dfs(vector<vector<int>>& s,vector<bool>& vis,int ind){
    //     vis[ind]=true;
    //     int r=s[ind][0], c=s[ind][1];

    //     for(int i=0;i<s.size();i++){
    //         if(vis[i]==false && (s[i][0]==r || s[i][1]==c))
    //             dfs(s,vis,i);
    //     }
    // }
    // int removeStones(vector<vector<int>>& stones) {
    //     int n=stones.size();
    //     vector<bool>vis(n);
    //     int g=0;

    //     for(int i=0;i<n;i++){
    //         if(vis[i])
    //             continue;
    //         dfs(stones,vis,i);
    //         g++;
    //     }
    //     return n-g;
    // }

    int find(int i,vector<int>& par){
        if(par[i]==i)
            return i;
        return par[i]=find(par[i],par);
    }

    // void uni(int i,int j,vector<int>& par,vector<vector<int>>& stones){
    //     int pari=find(i,par);
    //     int parj=find(j,par);
    //     if(pari==parj)
    //         return;
    //     par[parj]=pari;
    // }

    void uni(int i,int j,vector<int>& par, vector<int>& rnk){
        int pari=find(i,par);
        int parj=find(j,par);

        if(rnk[pari]==rnk[parj]){
            par[parj]=pari;
        }
        else if(rnk[pari]>rnk[parj]){
            par[parj]=pari;
        }
        else if(rnk[pari]<rnk[parj]){
            par[pari]=parj;
        }
        
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();

        vector<int> par(n);
        vector<int> rnk(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            rnk[i]=1;
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    uni(i,j,par,rnk);
                }
            }
        }
        int g=0;
        for(int i=0;i<n;i++){
            if(par[i]==i)
                g++;
        }
        return n-g;
    }
};