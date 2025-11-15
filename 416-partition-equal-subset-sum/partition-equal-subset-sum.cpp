class Solution {
public:
    vector<vector<int>>dp;
    bool equalsubset(vector<int>& arr, int i, int s,int s2){
        if(s2==(s/2))
            return true;
        if(i<0)
            return false;
        if(dp[i][s2]!=-1)
            return dp[i][s2];
        
        bool pick=false,notpick=false;
        if(s2<=(s/2))
            pick=equalsubset(arr,i-1,s,s2+arr[i]);
        notpick=equalsubset(arr,i-1,s,s2);

        return dp[i][s2]=(pick | notpick);
    }
    bool equalsubset1(vector<int>& arr, int i, int s1,int s2){
        if(s2==s1)
            return true;
        if(i<0)
            return false;
        if(dp[i][s1]!=-1)
            return dp[i][s1];
        
        bool pick=false,notpick=false;
        if(s2<=s1)
            pick=equalsubset1(arr,i-1,s1-arr[i],s2+arr[i]);
        notpick=equalsubset1(arr,i-1,s1,s2);

        return dp[i][s1]=(pick | notpick);
    }
    bool canPartition(vector<int>& nums) {
        int s1=0,s2=0;
        for(auto it:nums)
            s1+=it;
        if(s1%2!=0)
            return false;
        dp.resize(nums.size(),vector<int>(s1+1,-1));
        return equalsubset1(nums,nums.size()-1,s1,s2);
    }
};