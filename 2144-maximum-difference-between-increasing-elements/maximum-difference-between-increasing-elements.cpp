class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            int temp=nums[i];
            for(int j=i+1;j<n;j++){
                if(nums[j]>temp){
                    ans=max(ans,nums[j]-nums[i]);
                }
            }
        }
        return ans;
    }
};