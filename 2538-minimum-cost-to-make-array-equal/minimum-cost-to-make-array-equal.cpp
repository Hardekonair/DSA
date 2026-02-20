class Solution {
public: 
                    // EASY NOT OPTIMAL APPRAOCH = TLE
    // long long minCost(vector<int>& nums, vector<int>& cost) {
    //     unordered_map<int,int>mpp;
    //     int n=nums.size();

    //     vector<vector<int>>vec;
    //     for(int i=0;i<n;i++){
    //         vec.push_back({cost[i],nums[i]});
    //     }
    //     sort(vec.begin(),vec.end());
    //     for(int i=0;i<n;i++){
    //         cost[i]=vec[i][0];
    //         nums[i]=vec[i][1];
    //     }
    //     long long rans=1e18;
    //     for(int j=n-1;j>=0;j--){

    //         long long t=nums[j];
    //         long long ans=0;
    //         for(int i=0;i<n;i++){
    //             long long d=abs(nums[i]-t);
    //             long long c=d*cost[i];
    //             ans+=c;
    //         }
    //         rans=min(rans,ans);
    //     }
    //     return rans;
    // }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        vector<vector<int>>vec;
        long long totalweight=0;
        for(int i=0;i<n;i++){
            vec.push_back({nums[i],cost[i]});
            totalweight+=cost[i];
        }
        sort(vec.begin(),vec.end());
        long long half=0;
        if(totalweight%2==0)
            half=totalweight/2;
        else
            half=(totalweight+1)/2;
        
        long long prefix=0;
        long long t=0;
        for(int i=0;i<n;i++){
            prefix+=vec[i][1];
            if(prefix>=half){
                t=vec[i][0];
                break;
            }
        }
        // long long t=nums[target];
        long long ans=0;
        for(int i=0;i<n;i++){
            long long d=abs(nums[i]-t);
            long long c=d*cost[i];
            ans+=c;
        }
        return ans;

    }

};