class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        int n=n1+n2;
        if(n%2==0)
            return (nums1[n/2]+nums1[n/2-1])/2.0;
        return nums1[n/2];
        
    }
};