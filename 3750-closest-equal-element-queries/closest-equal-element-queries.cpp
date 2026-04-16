class Solution {
public:
    // imp case - [14,14,4,2,19,19,14,19,14], [2,4,8,6,3]
                                        // OPTIMAL - WORST CASE - O(LOG N)
    int find(int i,int j,int n){
        int diff=abs(i-j);
        return min(diff,n-diff);
    }
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){ 
            mpp[nums[i]].push_back(i);
        }

        vector<int>ans;

        for(auto ind:queries){
            int target=nums[ind];
            auto &vec=mpp[target];
            if(vec.size()<2)
                ans.push_back(-1);
            else{
                auto it1=lower_bound(vec.begin(),vec.end(),ind);
                auto it2=upper_bound(vec.begin(),vec.end(),ind);
                int dis=INT_MAX;

                int next=(it2==vec.end()?vec[0]:*it2);
                int prev=(it1==vec.begin()?vec.back():*(it1-1));
                
                // if(next!=-1)    dis=min(dis,find(ind,next,n));
                // if(prev!=-1)    dis=min(dis,find(ind,prev,n));
                dis=min(find(ind,next,n),find(ind,prev,n));
                
                ans.push_back(dis);

            }
        }
        return ans;
    }


                                        //BETTER - worst case - O(n2)
    // vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    //     int n=nums.size();
    //     unordered_map<int,vector<int>>mpp;
    //     for(int i=0;i<n;i++){ 
    //         mpp[nums[i]].push_back(i);
    //     }
    //     vector<int>ans;
    //     for(auto it:queries){
    //         int dis=1e9;
    //         for(auto ind:mpp[nums[it]]){
    //             if(ind==it)continue;
    //             dis=min(dis,min(abs(ind-it),(n+min(ind,it)-max(ind,it))));
    //         }
    //         ans.push_back(dis==1e9?-1:dis);
    //     }
    //     return ans;
    // }
                                        // brute- worst case - O(n2)
    // vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    //     int n=nums.size();
        
    //     vector<int>ans;

    //     for(auto it:queries){
    //         int i=it,j=it;
    //         bool f=false;
    //         for(int steps=1;steps<=n/2;steps++){
    //             if(nums[(i-steps+n)%n]==nums[it] || nums[(i+steps)%n]==nums[it]){    
    //                 ans.push_back(steps);   
    //                 f=true;
    //                 break;
    //             }
    //         }
    //         if(f==false)    ans.push_back(-1);
    //     }
    //     return ans;
    // }
};