class Solution {
public:
    // int solve(int i,int sum,int mini,int count,int k,vector<int>&nums1, vector<int>&nums2){
    //     if(count==k)
    //         return sum*mini;
    //     if(i>=nums1.size())
    //         return 0;
        
    //     int take=solve(i+1,sum+nums1[i],min(mini,nums2[i]),count+1,k,nums1,nums2);
    //     int nottake=solve(i+1,sum,mini,count,k,nums1,nums2);

    //     return max(take,nottake);
    // }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // return solve(0,0,INT_MAX,0,k,nums1,nums2);

        vector<pair<int,int>>vec;
        for(int i=0;i<nums1.size();i++){
            vec.push_back({nums1[i],nums2[i]});
        }

        sort(vec.begin(),vec.end(),[](auto &a,auto &b){return a.second>b.second;});

        long long sum=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<k;i++){
            sum+=vec[i].first;
            pq.push(vec[i].first);
        }

        long long ans=sum*vec[k-1].second;
        for(int i=k;i<nums1.size();i++){
            sum-=pq.top();
            pq.pop();
            sum+=vec[i].first;
            pq.push(vec[i].first);
            ans=max(ans,sum*vec[i].second);
        }

        return ans;
    }
};