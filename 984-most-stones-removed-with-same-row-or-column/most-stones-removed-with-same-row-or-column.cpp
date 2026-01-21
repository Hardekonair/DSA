class Solution {
public:
    void dfs(vector<vector<int>>& s,vector<bool>& vis,int ind){
        vis[ind]=true;
        int r=s[ind][0], c=s[ind][1];

        for(int i=0;i<s.size();i++){
            if(vis[i]==false && (s[i][0]==r || s[i][1]==c))
                dfs(s,vis,i);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool>vis(n);
        int g=0;

        for(int i=0;i<n;i++){
            if(vis[i])
                continue;
            dfs(stones,vis,i);
            g++;
        }
        return n-g;
    }
};