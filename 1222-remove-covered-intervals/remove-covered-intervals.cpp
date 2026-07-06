class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int count=0;

        if(n==1)
            return n;

        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });
        int maxend=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][1]>maxend){
                count++;
                maxend=intervals[i][1];
            }
        }
        return count+1;
    }
};