class Solution {
public:
    int maxDistance(vector<int>& arr){
        int n=arr.size();
        int left=0,right=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=arr[n-1]){
                left=abs(n-1-i);
                break;
            }
        }
        for(int j=n-1;j>=0;j--){
            if(arr[j]!=arr[0]){
                right=abs(j);
                break;
            }
        }
        return max(left,right);
    }
    // int dp[100][100];
    // int solve(int i,int j,vector<int>& colors){
    //     if(colors[i]!=colors[j])
    //         return abs(j-i);
    //     if(dp[i][j]!=-1)    
    //         return dp[i][j];
    //     return dp[i][j]=max(solve(i+1,j,colors),solve(i,j-1,colors));
    // }
    // int maxDistance(vector<int>& colors) {
    //     memset(dp,-1,sizeof(dp));
    //     return solve(0,colors.size()-1,colors);
    // }
};