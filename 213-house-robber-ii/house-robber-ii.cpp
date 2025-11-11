class Solution {
public: 
    int helper(vector<int> nums){    // SAME AS HOUSE ROBBER 1
        int prev1=nums[0], prev2=0;

        for(int i=1;i<nums.size();i++){
            int pick=nums[i]+prev2;
            int notpick=0+prev1;

            int cur=max(pick,notpick);
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        vector<int> t1,t2;
        int n=nums.size();

        if(n==1)
            return nums[0];
        for(int i=0;i<n;i++){
            if(i!=n-1)
                t1.push_back(nums[i]);
            if(i!=0)
                t2.push_back(nums[i]);
        }

        return max(helper(t1),helper(t2));
        
    }
};