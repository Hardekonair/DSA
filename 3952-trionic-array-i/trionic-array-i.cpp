class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int count=3;
        bool temp=false;
        int i=0;
        
        while(i<n-1 && nums[i]<nums[i+1])   i++;
        if(i==0 || i==n-1)    // NO/ALL INCREASING
            return false;

        int mid=i;
        while(i<n-1 && nums[i]>nums[i+1])   i++;
        if(mid==i || i==n-1)  // NO/ALL DECREASING
            return false;

        while(i<n-1 && nums[i]<nums[i+1])   i++;
        if(i!=n-1)
            return false;

        return true;
    }
};