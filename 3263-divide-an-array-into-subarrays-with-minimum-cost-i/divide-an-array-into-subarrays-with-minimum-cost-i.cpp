class Solution {
public:
    int minimumCost(vector<int>& nums) {
        // int n=nums.size();
        // int sum=INT_MAX;
        // int spos=INT_MAX;
        // int fpos=nums[0];
        // for(int i=1;i<n-1;i++){
        //     spos=min(spos,nums[i]);
        //     int tpos=INT_MAX;
        //     for(int j=i+1;j<n;j++){
        //         tpos=min(tpos,nums[j]);
        //     }
        //     int rawsum=fpos+spos+tpos;
        //     sum=min(sum,rawsum);
        // }
        // return sum;

        // int n=nums.size();
        // int first=nums[0];
        
        // int second=51,third=51;
        // for(int i=1;i<n;i++){
        //     int curr=nums[i];

        //     if(curr<=second){
        //         third=second;
        //         second=curr;
        //     }
        //     else if(curr<third){
        //         third=curr;
        //     }


        // }
        // first+=second+third;
        // return first;

        int a=nums[0],b=INT_MAX,c=INT_MAX;
        int n=nums.size();
        for(int i=1;i<n;i++){
            // if(nums[i]<a){
            //     c=b;
            //     b=a;
            //     a=nums[i];
            // }
            if(nums[i]<b){
                c=b;
                b=nums[i];
            }
            else if(nums[i]<c)
                c=nums[i];
        }

        return a+b+c;        
    }
};