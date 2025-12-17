class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int v=numCourses;
        vector<vector<int>> adj(v);
        for(auto it:pre){
            adj[it[0]].push_back(it[1]);
        }

        vector<int> ind(v,0);
        for(auto it:pre){
            ind[it[1]]++;
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
            return true;
        return false;
    }
};