class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_set<int>evenst, oddst;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0){
                    if(evenst.find(nums[j])==evenst.end()){
                        evenst.insert(nums[j]);
                    }
                }
                else{
                    if(oddst.find(nums[j])==oddst.end()){
                        oddst.insert(nums[j]);
                    }                    
                }
                if(evenst.size()==oddst.size())
                    ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};