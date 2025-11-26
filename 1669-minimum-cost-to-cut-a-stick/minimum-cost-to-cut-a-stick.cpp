class Solution {
public:
    vector<vector<int>> dp;
    int costcut(vector<int>& cuts,int i,int j){
        if(i+1>j-1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int result=INT_MAX;
        for(int ind=i+1;ind<j;ind++){
            int cost=cuts[j]-cuts[i] + costcut(cuts,i,ind) + costcut(cuts,ind,j);

            result=min(result,cost);
        }
        return dp[i][j]=result;
    }
    int minCost(int n, vector<int>& cuts) {
        dp.resize(cuts.size()+1,vector<int>(cuts.size()+2,-1));
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return costcut(cuts,0,cuts.size()-1);
    }
};