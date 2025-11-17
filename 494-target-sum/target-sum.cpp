class Solution {
public:
    int helper(vector<int>& nums,int target,int i,int c){
        if(i<0){
            if(target==c)
                return 1;
            // if(target!=c)
                return 0;
        }

        int pos=helper(nums,target,i-1,c+nums[i]);
        int neg=helper(nums,target,i-1,c-nums[i]);

        return pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int c=0;
        return helper(nums,target,nums.size()-1,c);
    }
};