class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
                                // T.C- O(n), S.C- O(n)
        unordered_set<int> temp(nums1.begin(),nums1.end());
        unordered_set<int>ans;
        for(auto it:nums2){
            if(temp.count(it)){
                ans.insert(it);
            }
        }
        return vector<int>(ans.begin(),ans.end());


                            // T.C- O(n logn)

        // vector<int> ans;
        // int n1=nums1.size();
        // int n2=nums2.size();
        // int i=0,j=0;
        // sort(nums1.begin(),nums1.end());
        // sort(nums2.begin(),nums2.end());
        // while(i<n1 && j<n2){
        //     if(nums1[i]==nums2[j] ){
        //         if (ans.empty() || ans.back()!=nums1[i] )
        //             ans.push_back(nums1[i]);
        //         i++;
        //         j++;

        //     }
        //     else if(nums1[i]<nums2[j]){
        //         i++;
        //     }
        //     else
        //         j++;
        // }
        // return ans;
        
    }
};