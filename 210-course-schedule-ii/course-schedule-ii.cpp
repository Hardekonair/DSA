class Solution {
public:
    vector<int> findOrder(int  v, vector<vector<int>>& pre) {
        
        vector<vector<int>> adj(v);
        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> ind(v,0);
        for(auto it:pre){
            ind[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<v;i++){
            if(ind[i]==0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);

            for(auto it:adj[x]){
                ind[it]--;
                if(ind[it]==0)
                    q.push(it);
            }
        }
        if(ans.size()==v)
            return ans;
        return {};
    
    }
};