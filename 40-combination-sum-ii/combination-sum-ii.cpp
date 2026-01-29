class Solution {
public:
    void combsum2(int i,int t,vector<int>& arr,vector<int>& temp,vector<vector<int>>& ans){
        if(t==0){
            ans.push_back(temp);
            return;
        }
        if(i<0)
            return;
        if(t>=arr[i]){
        temp.push_back(arr[i]);
        combsum2(i-1,t-arr[i],arr,temp,ans);
        temp.pop_back();
        }
        int j=i-1;
        while(j>=0 && arr[j]==arr[i])
            j--;
        if(j>=0){
            combsum2(j,t,arr,temp,ans);
        }
    }
    void solve(int i,int target,vector<int>& arr,vector<int> &temp,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<arr.size();j++){
            if(j>i && arr[j]==arr[j-1])
                continue;
            if(arr[j]>target)
                break;
            temp.push_back(arr[j]);
            solve(j+1,target-arr[j],arr,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        // solve(0,target,candidates,temp,ans);
        combsum2(n-1,target,candidates,temp,ans);
        return ans;

        
    }
};