class Solution {
public:
    void cs3(int start,int t,int p,vector<int>& temp,vector<vector<int>>& ans){
        if(p==0 || t==0){
            if(p==0 && t==0)
                ans.push_back(temp);
            return;
        }
        for(int i=start;i<=9;i++){
            temp.push_back(i);
            cs3(i+1,t-i,p-1,temp,ans);
            temp.pop_back();
        }
    }
    void solve(int ind,int k,int n,vector<int>& temp,vector<vector<int>>& ans){
        if(k==0){
            if(n==0)
                ans.push_back(temp);
            return;
        }
        if(k>=n)
            return;
        for(int i=ind;i<10;i++){
            temp.push_back(i);
            solve(i+1,k-1,n-i,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        // solve(1,k,n,temp,ans);
        cs3(1,n,k,temp,ans);
        return ans;
        
    }
};