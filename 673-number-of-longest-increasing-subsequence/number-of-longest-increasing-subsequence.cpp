class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1),cnt(nums.size(),1);
        int maxlen=1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    cnt[i]=cnt[j];
                }
                else if(nums[j]<nums[i] && dp[i]==dp[j]+1)
                    cnt[i]+=cnt[j];
            }
            if(dp[i]>maxlen){
                maxlen=dp[i];
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(dp[i]==maxlen)
                ans+=cnt[i];
        }
        return ans;
    }
};