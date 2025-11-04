class Solution {
public:
    int pivotIndex(vector<int>& nums) {
                                            // OPTIMAL APPROACH
                        
        int n=nums.size();
        int total=0;
        for(int it:nums)
            total+=it;
        
        int left=0;
        for(int i=0;i<n;i++){
            int right=total-left-nums[i];

            if(left==right)
                return i;
            
            left+=nums[i];
        }
        return -1;
                                            // BRUTE FORCE APPROACH

        // int n=nums.size();

        // for(int i=0;i<n;i++){
        //     int ls=0,rs=0,l=i-1,r=i+1;
        //     while(l>=0){
        //         ls+=nums[l--];
        //     }
        //     while(r<n){
        //         rs+=nums[r++];
        //     }
        //     if(ls==rs)
        //         return i;
        // }
        // return -1;
    }
};