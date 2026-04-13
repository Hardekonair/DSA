class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n=nums.size();        
        int i=start,j=start;
        while(i<n && j>=0){
            if(nums[i]==target)
                return abs(i-start);
            
            if(nums[j]==target)
                return abs(j-start);

            i++,j--;
        }
        while(i<n){
            if(nums[i]==target)
                return abs(i-start);
            i++;
        }
        while(j<n){
            if(nums[j]==target)
                return abs(j-start);
            j--;
        }
        return 0;
    }
};