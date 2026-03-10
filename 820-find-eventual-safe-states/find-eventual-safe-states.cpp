class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<vector<int>>revadj(v);
        vector<int> ind(v);

        for(int i=0;i<v;i++){
            for(auto &it:graph[i]){
                revadj[it].push_back(i);
                ind[i]++;
            }
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
            for(auto &it:revadj[x]){
                ind[it]--;
                if(ind[it]==0)
                    q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};