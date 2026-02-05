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
    // LEFT TO RIGHT APPROACH
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
            s2+=it;
        // if(s1%2!=0)
        //     return false;
        dp.resize(nums.size(),vector<int>(s2+1,-1));
        // return equalsubset1(nums,nums.size()-1,s1,s2);
        return equalpart(nums.size()-1,s1,s2,nums);
    }
};