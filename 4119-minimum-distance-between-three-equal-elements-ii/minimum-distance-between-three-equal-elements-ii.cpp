class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans=1e9;

        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }

        for(auto it:mpp){
            vector<int>arr=it.second;
            if(arr.size()<3)    continue;

            for(int i=0;i+2<arr.size();i++){
                int x=2*(arr[i+2]-arr[i]);
                ans=min(ans,x);
            }
        }
        return ans==1e9?-1:ans;
    }
};