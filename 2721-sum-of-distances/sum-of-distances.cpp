class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,long long> indexCount,indexsum;
        vector<long long>left(n,0);

        for(int i=0;i<n;i++){
            long long count=indexCount[nums[i]];
            long long sum=indexsum[nums[i]];
            left[i]+=count*i-sum;
            indexCount[nums[i]]++;
            indexsum[nums[i]]+=i;
        }

        indexCount.clear(),indexsum.clear();

        for(int i=n-1;i>=0;i--){
            long long count=indexCount[nums[i]];
            long long sum=indexsum[nums[i]];
            left[i]+=sum-count*i;
            indexCount[nums[i]]++;
            indexsum[nums[i]]+=i;
        }

        return left;
    }
};