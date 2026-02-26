class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
                                    //  USING TOPOSORT

        // CREATING A DIRECTED GRAPH OF COURSES
        int n=numCourses;
        vector<vector<int>>adj(n);

        vector<int>indegree(n,0);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        
        // STORING INDEGREE OF 0, THAT WILL START THE COURSES
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        // TRAVERSING ZERO INDEGREE AND REDUCING CONNECTED COMP DEGREE
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }

        // CHECKING IF ALL COURSES ARE NOT VISITED = IF ALL INDEGREE 0 OR NOT
        for (auto deg: indegree){
            if(deg!=0){
                return false;
            }
        }
        return true;
    }
};