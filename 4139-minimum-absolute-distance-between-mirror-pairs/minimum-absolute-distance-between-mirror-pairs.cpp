class Solution {
public:
    int reversedig(int a){
        int val=0;
        while(a){
            int rem=a%10;
            val=val*10+rem;
            a/=10;
        }
        return val;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int ans=1e9;
        unordered_map<int,int>mpp;

        // sort(nums.begin(),nums.end());
        
        for(int i=nums.size()-1;i>=0 ; i--){
            int a=nums[i], b=reversedig(nums[i]);
            if(mpp.find(b)!=mpp.end())
                ans=min(ans,abs(i-mpp[b]));
            mpp[nums[i]]=i;
        }
        return ans==1e9?-1:ans;
    }
};