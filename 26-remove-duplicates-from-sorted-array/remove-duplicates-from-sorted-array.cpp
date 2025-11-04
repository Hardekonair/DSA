class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=1;
        while(j<n){
            if(nums[j]!=nums[i]){
                i++;
                nums[i]=nums[j];
            }
            else
                j++;
        }
        return i+1;

        
        // int n=nums.size();
        // int i=0;
        // for(int j=1;j<n;j++){
        //     if(nums[j]!=nums[i]){
        //         nums[++i]=nums[j];
        // }
        // }
        // return i+1;


       

        // int n=nums.size();
        // set<int> sets;
        // for(int i=0;i<n;i++){
        //     sets.insert(nums[i]);
        // }
        // int k=sets.size();
        // int j=0;
        // for(auto x:sets){
        //     nums[j++]=x;
        // }
            
        // return k;
    }
};