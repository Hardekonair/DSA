class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,deque<int>>mpp;
        int ans=1e9;
        
        for(int i=0;i<n;i++){
            auto &dq=mpp[nums[i]];
            dq.push_back(i);

            if(dq.size()>3) dq.pop_front();

            if(dq.size()==3){
                int x=2*(dq.back()-dq.front());
                ans=min(ans,x);
            }
        }
        return ans==1e9?-1:ans;
    }
};