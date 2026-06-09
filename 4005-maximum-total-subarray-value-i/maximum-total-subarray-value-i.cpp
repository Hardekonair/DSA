class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return (long long)k*(nums[nums.size()-1]-nums[0]);
    }
};