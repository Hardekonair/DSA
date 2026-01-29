class Solution {
public:
    void combsum(int i, int target, vector<int>& temp, vector<vector<int>>& ans,
                 vector<int>& arr) {
        // if(i<0){
        //     if(target==0){
        //         ans.push_back(temp);
        //     }
        //     return;
        // }

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (i == 0) {
            if (target % arr[0] == 0) {
                int cnt = target / arr[0];
                for (int k = 0; k < cnt; k++)
                    temp.push_back(arr[0]);

                ans.push_back(temp);

                for (int k = 0; k < cnt; k++)
                    temp.pop_back(); // backtrack
            }
            return;
        }

        combsum(i - 1, target, temp, ans, arr);
        if (arr[i] <= target) {
            temp.push_back(arr[i]);
            combsum(i, target - arr[i], temp, ans, arr);
            temp.pop_back();
        }
    }

    // void findcomb(int i,int t,vector<int>& arr, vector<int>&
    // temp,vector<vector<int>>& ans){
    //     if(i==arr.size()){
    //         if(t==0)
    //             ans.push_back(temp);
    //     return;
    //     }

    //     if(arr[i]<=t){
    //         temp.push_back(arr[i]);
    //         findcomb(i,t-arr[i],arr,temp,ans);
    //         temp.pop_back();
    //     }
    //     findcomb(i+1,t,arr,temp,ans);
    // }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();

        combsum(n - 1, target, temp, ans, candidates);

        return ans;
    }
};