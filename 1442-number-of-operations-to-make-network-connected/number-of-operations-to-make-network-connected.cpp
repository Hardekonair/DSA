class Solution {
public:
    int find(vector<int>& par,int x){
        if(par[x]==x)
            return x;
        return par[x]=find(par,par[x]);
    }
    bool uni(vector<int>& par,int u, int v){
        int pu=find(par,u), pv=find(par,v);
        if(pu==pv)
            return false;
        par[pu]=pv;
        return true;
    }
    int makeConnected(int n, vector<vector<int>>& conn) {

        vector<int> par(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }

        int extraedge=0;
        for(auto it:conn){
            if(uni(par,it[0],it[1])==false)
            extraedge++;
        }

        int component=0;
        for(int i=0;i<n;i++){
            if(find(par,i)==i)
                component++;
        }

        if(extraedge>=component-1)
            return component-1;
        return -1;
    }
};