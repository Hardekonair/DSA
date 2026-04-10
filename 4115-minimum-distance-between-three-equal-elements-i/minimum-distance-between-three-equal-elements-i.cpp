class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }

        vector<vector<int>>vec;
        int ans=1e9;
        for(auto it:mpp){
            if(it.second.size()>2){
                vector<int>arr=it.second;
                for(int i=0;i+2<arr.size();i++){
                    int j=i+2;
                    int x=2*(arr[j]-arr[i]);
                    ans=min(ans,x);
                }                
            }
        }
        return ans==1e9?-1:ans;
    }
};