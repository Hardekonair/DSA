class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int mid=0,low=0,high=n-1;                                  
        while(mid<=high){
            if(nums[mid]==1)
                mid++;
            else if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                mid++;
                low++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }



                            //BRUTE FORCE
        // int c1=0,c2=0,c0=0;
    //     for(int i=0;i<n;i++){
    //         if(nums[i]==0)
    //             c0++;
    //         else if(nums[i]==1)
    //             c1++;
    //         else if(nums[i]==2)
    //             c2++;
    //     }
    //     int j=0;
    //     for(int i=0;i<c0;i++)
    //         nums[j++]=0;
    //     for(int i=0;i<c1;i++)
    //         nums[j++]=1;
    //     for(int i=0;i<c2;i++)
    //         nums[j++]=2;
    }
};