class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //Brute Force
            // int n=nums.size();
            // k=k%n;
            // vector<int> temp(n-k);
            // for(int i=0;i<n-k;i++)
            //     temp[i]=nums[i];

            // for(int i=n-k;i<n;i++)
            //     nums[i-(n-k)]=nums[i];
            
            // for(int i=k;i<n;i++)
            //     nums[i]=temp[i-(k)];

        //Optimal Approach
            int n=nums.size();
            k=k%n;
            reverse(nums.begin(),nums.begin()+(n-k));
            reverse(nums.begin()+(n-k),nums.end());
            reverse(nums.begin(),nums.end());

        // space complexity less
        //      int n = nums.size();
        // k = k % n;
        // if (k != 0) {
        //     vector<int> temp(nums.end() - k, nums.end());
        //     temp.insert(temp.end(), nums.begin(), nums.end() - k);
        //     copy(temp.begin(), temp.end(), nums.begin());
    }
    
};