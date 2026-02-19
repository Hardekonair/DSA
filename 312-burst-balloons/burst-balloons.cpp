class Solution {
public:
    vector<vector<int>>dp;
    int fn1(int i,int j,vector<int>& cuts){
        if(i+1>j-1){
            return 0;
        }
        if(dp[i][j]!=-1)    
            return dp[i][j];
        int ans=0;
        for(int k=i+1;k<j;k++){
            int cost=cuts[i]*cuts[j]*cuts[k]+fn1(i,k,cuts)+fn1(k,j,cuts);
            ans=max(ans,cost);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin()+0,1);
        nums.push_back(1);
        dp.resize(nums.size(),vector<int>(nums.size(),-1));
        return fn1(0,nums.size()-1,nums);
    }
};