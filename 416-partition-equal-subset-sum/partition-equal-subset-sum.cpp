class Solution {
public:
    vector<vector<int>>dp;
    // RIGHT TO LEFT APRAOCH
    bool equalpart(int i,int s1,int s2,vector<int>& arr){
        if(s1==s2)
            return true;
        if(s2<s1)
            return false;
        if(i==0){
            return (s1 + arr[0] == s2 - arr[0]);
        }
        if(dp[i][s1]!=-1)
            return dp[i][s1];
        return dp[i][s1]=equalpart(i-1,s1,s2,arr) || equalpart(i-1,s1+arr[i],s2-arr[i],arr);
    }
    bool equalsubset(vector<int>& arr, int i, int s2,int s){
        if(s2==(s/2))
            return true;
        if(i==0)
            return (s2+arr[i]==(s/2));
        if(dp[i][s2]!=-1)
            return dp[i][s2];
        
        bool pick=false,notpick=equalsubset(arr,i-1,s2,s);
        if(s2 + arr[i]<=(s/2))
            pick=equalsubset(arr,i-1,s2+arr[i],s);

        return dp[i][s2]=(pick || notpick);
    }

    
    bool canPartition(vector<int>& nums) {
        int s1=0,s2=0;
        for(auto it:nums)
            s2+=it;
        if(s2%2!=0)
            return false;
        dp.resize(nums.size(),vector<int>(s2+1,-1));
        return equalsubset(nums,nums.size()-1,s1,s2);
        // return equalpart(nums.size()-1,s1,s2,nums);
    }
};