class Solution {
public:
    bool ispossible(int mid, vector<vector<int>>& tasks){

        for(auto it:tasks){
            if(it[1]<=mid){
                mid-=it[0];
            }
            else
                return false;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int left = 0, right = 1e9;
        int ans = -1;

        sort(tasks.begin(),tasks.end(),
            [](const vector<int>& a, const vector<int>& b)
            {
                return a[1]-a[0]>b[1]-b[0];
            }
        );

        while(left <= right){
            int mid=left+(right-left)/2;

            if(ispossible(mid,tasks)){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};