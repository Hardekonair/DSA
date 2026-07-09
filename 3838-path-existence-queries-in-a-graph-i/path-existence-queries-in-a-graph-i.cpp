class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>prep(n);
        // int start=0;
        prep[0]=0;
        for(int i=0;i<n-1;i++){
            if(abs(nums[i]-nums[i+1])<=maxDiff){
                prep[i+1]=prep[i];
            }
            else{
                prep[i+1]=prep[i]+1;
                // start++;
            }
        }

        vector<bool>ans;
        for(auto it:queries){
            int a=it[0],b=it[1];
            if(prep[a]==prep[b])
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};