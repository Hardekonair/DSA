class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,vector<int>>mpp;
        
        sort(nums.begin(),nums.end());

        for(auto it:nums){
            mpp[it%space].push_back(it);
        }

        int maxsize=0;
        int ans=INT_MAX;
        for(auto it:mpp){
            if(it.second.size()>maxsize){
                maxsize=it.second.size();
                ans=it.second[0];
            }
            if(it.second.size()==maxsize){
                ans=min(ans,it.second[0]);
            }
        }
        return ans;
    }
};