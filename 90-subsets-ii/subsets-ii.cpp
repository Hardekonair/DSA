class Solution {
public:
    void subset2(int i,vector<int>& temp,vector<vector<int>>& ans,vector<int>& nums){
        if(i<0){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        subset2(i-1,temp,ans,nums);
        temp.pop_back();
        int j=i-1;
        while(j>=0 && nums[i]==nums[j])
            j--;
        subset2(j,temp,ans,nums);
        
    }



    void solve(int i,vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        ans.push_back(temp);
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1]){
                continue;
            }
            temp.push_back(nums[j]);
            solve(j+1,nums,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        // solve(0,nums,temp,ans);
        subset2(n-1,temp,ans,nums);
        return ans;
    }
};