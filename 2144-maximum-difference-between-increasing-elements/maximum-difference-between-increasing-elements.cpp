class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();

        int mini=nums[0];
        int ans=-1;

        for(int i=1;i<n;i++){
            if(mini<nums[i]){
                ans=max(ans,nums[i]-mini);
            }
            mini=min(mini,nums[i]);
        }
        return ans;
    }
};