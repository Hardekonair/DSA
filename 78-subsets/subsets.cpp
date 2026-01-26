class Solution {
public:
    void subset(int i,vector<int> &nums,vector<int> &temp,vector<vector<int>> &ans){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        subset(i+1,nums,temp,ans);
        temp.pop_back();
        subset(i+1,nums,temp,ans);
    }

    void fn(int i,vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans){
        if(i<0){
            ans.push_back(temp);
            return;
        }
        fn(i-1,nums,temp,ans);
        temp.push_back(nums[i]);
        fn(i-1,nums,temp,ans);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()==0)
            return ans;
        vector<int> temp;
        // subset(0,nums,temp,ans);
        fn(nums.size()-1,nums,temp,ans);
        return ans;
        
    }
};