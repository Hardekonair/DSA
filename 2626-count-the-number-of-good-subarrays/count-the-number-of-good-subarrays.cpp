class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int i=0, j=0;
        int n=nums.size();
        unordered_map<int,int>freq;
        int pairs=0;
        long long ans=0;

        // while(i<=j && j<=n){
        //     if(pairs>=k){
        //         ans+=n-j;
        //         // int c=((mpp[i]*mpp[i]-1)/2) - (((mpp[i]-1)*(mpp[i]-2))/2);
        //         pairs-=mpp[nums[i]]-1;
        //         mpp[nums[i]]--;
        //         i++;
        //     }
        //     else if(j<n){
        //         mpp[nums[j]]++;
        //         pairs+=mpp[nums[j]]-1;
        //         j++;
        //     }
        //     else    
        //         break;
        // }
        for (int j = 0; j < n; j++) {

            // Add nums[j]
            pairs += freq[nums[j]];
            freq[nums[j]]++;

            // Current window has >= k pairs
            while (pairs >= k) {

                ans += n - j;

                // Remove nums[i]
                freq[nums[i]]--;
                pairs -= freq[nums[i]];

                i++;
            }
        }
        return ans;
    }
};