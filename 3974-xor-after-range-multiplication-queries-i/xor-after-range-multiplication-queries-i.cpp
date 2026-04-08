class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto it:queries){
            int l=it[0],r=it[1],k=it[2],v=it[3];
            while(l<=r){
                nums[l]=(1LL * nums[l]*v)%(int)(1e9+7);    //int * int → may overflow before modulo, long long * int → safe → then modulo
                l+=k;
            }
        }
        int ans=0;
        for(auto it:nums){
            ans^=it;
        }
        return ans;
    }
};