class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }

        vector<vector<int>>vec;
        for(auto it:mpp){
            if(it.second.size()>2){
                vec.push_back(it.second);
            }
        }
        if(vec.empty()) return -1;
        int ans=1e9;
        for(auto it:vec){
            for(int i=0;i<it.size()-2;i++){
                int j=i+2;
                int x=2*(it[j]-it[i]);
                ans=min(ans,x);
            }
        }
        return ans;
    }
};