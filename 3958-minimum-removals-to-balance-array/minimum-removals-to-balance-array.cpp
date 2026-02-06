class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int i=0,j=0;
        int ans=0;
        while(j<n){
            if(nums[j]<=(long long)k*nums[i]){
                ans=max(ans,j-i+1);
                j++;
            }
            else
                i++;
        }
        return n-ans;
    }
};