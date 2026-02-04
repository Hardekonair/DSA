class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int count=3;
        bool temp=false;
        int i=0;
        
        while(i<n-1 && count==3 && nums[i]<nums[i+1]){
        temp=true;
        i++;}
        if(temp)count--;

        while(i<n-1 && count==2 && nums[i]>nums[i+1]){
            temp=false;
            i++;
        }
        if(temp==false) count--;

        while(i<n-1 && count==1 && nums[i]<nums[i+1]){
            i++;
            temp=true;
        }
        if(temp)
            count--;

        if(count==0 && i==n-1) return true;
        return false;

    }
};