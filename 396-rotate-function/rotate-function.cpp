class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int maxans=INT_MIN;
        
        int prevans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            prevans+=i*nums[i];
            sum+=nums[i];
        }
        maxans=prevans;
        for(int i=n-1;i>0;i--){
            int newans=prevans+sum-(n*nums[i]);

            maxans=max(maxans,newans);
            prevans=newans;
        }
        return maxans;
    }
};