class Solution {
public:
    vector<vector<long long>> dp;
    long long solve(int i,int j,vector<int>& robot,vector<int>& slots){
        if(i>=robot.size())  return 0;
        if(j>=slots.size())  return 1e18;

        if(dp[i][j]!=-1)    return dp[i][j];

        return dp[i][j]=min(abs((long long)slots[j]-robot[i])+solve(i+1,j+1,robot,slots),solve(i,j+1,robot,slots));
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        vector<int>slots;
        for(auto it:factory){
            slots.insert(slots.end(),it[1],it[0]);
        }

        dp.resize(robot.size(),vector<long long>(slots.size(),-1));
        return solve(0,0,robot,slots);
    }
};