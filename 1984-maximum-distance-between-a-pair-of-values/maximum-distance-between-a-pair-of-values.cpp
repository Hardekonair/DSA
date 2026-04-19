class Solution {
public:
    // lower_bound returns an iterator to: the first element ≥ target
    // lower_bound works only on asc order sorted array
    // index = iterator - arr.begin();
    int bs(int target,int i,vector<int>& nums){
        int l=i+1,r=nums.size()-1;
        int ans=nums.size();
        while(l<=r){
            int mid=l+((r-l)/2);

            if(nums[mid]<target){
                r=mid-1;  // try to find earlier index
            }
            else{
                ans=mid;
                l=mid+1;
            }
        }
        return ans==nums.size()?i:ans;
    }
    // int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    //     int n=nums1.size();
    //     int ans=0;

    //     for(int i=0;i<n;i++){
    //         int a=i;
    //         int b=bs(nums1[i],i,nums2);
    //         ans=max(ans,b-a);
    //     }
    //     return ans;
    // }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0, ans = 0;

    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] <= nums2[j]) {
            ans = max(ans, j - i);
            j++;
        } else {
            i++;
        }
    }
    return ans;
}
};