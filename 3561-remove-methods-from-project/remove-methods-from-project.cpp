class Solution {
public:
    bool dfs(int i,vector<vector<int>>& adj, vector<int>& grp){
        for(auto it:adj[i]){ 
            if(grp[it]==0){
                grp[it]=grp[i];
                if(dfs(it,adj,grp)==false)
                    return false;

            }
            else if(grp[it]==-1)
                return false;
        }
        return true;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>grp(n,0);
        vector<vector<int>>adj(n);

        for(auto it:invocations){
            adj[it[0]].push_back(it[1]);
        }

        queue<int>q;
        q.push(k);
        vector<int>vis(n,0);
        
        while(!q.empty()){
            int a=q.front();
            q.pop();
            vis[a]=1;

            grp[a]=-1;
            for(auto it:adj[a]){
                if(vis[it]==0)
                    q.push(it);
            }
        }

        vector<int>temp;
        for(int i=0;i<n;i++){
            temp.push_back(i);
        }

        int j=1;
        for(int i=0;i<n;i++){
            if(grp[i]==0){
                grp[i]=j++;
                if(dfs(i,adj,grp)==false)
                    return temp;
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(grp[i]!=-1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};