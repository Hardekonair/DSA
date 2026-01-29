class Solution {
public:
    void findcomb(int i,int t,vector<int>& arr, vector<int>& temp,vector<vector<int>>& ans){
        if(i==arr.size()){
            if(t==0)
                ans.push_back(temp);
        return;
        }

        if(arr[i]<=t){
            temp.push_back(arr[i]);
            findcomb(i,t-arr[i],arr,temp,ans);
            temp.pop_back();
        }
        findcomb(i+1,t,arr,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int i=0;
        
        findcomb(i,target,candidates,temp,ans);

        return ans;
        
    }
};