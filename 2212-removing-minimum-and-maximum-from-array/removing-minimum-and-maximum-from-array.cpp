class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
       int n=nums.size();
       int mini=INT_MAX,maxi=INT_MIN;
       int minloc=-1,maxloc=-1;
       for(int i=0;i<n;i++){
        if(nums[i]<mini){
            mini=nums[i];
            minloc=i;
        }
        if(nums[i]>maxi){
            maxi=nums[i];
            maxloc=i;
        }
       }
        int ans1=max(minloc,maxloc)+1;  // DELETION FROM FRONT
        int ans2=n-min(minloc,maxloc);  // DELETION FROM BACK
        int ans3=min(minloc,maxloc)+1+n-max(maxloc,minloc);  // DELETION FROM BOTH ENDS
        
        return min(min(ans1, ans2), ans3);
    }
};