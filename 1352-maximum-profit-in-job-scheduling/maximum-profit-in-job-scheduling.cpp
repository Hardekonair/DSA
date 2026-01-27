class Solution {
public:
    vector<int> dp;
    int fn(int i,vector<vector<int>>& vec){
        if(i==0){
            return vec[i][2];
        }

        if(dp[i]!=-1)
            return dp[i];

        int nt=fn(i-1,vec);
        int t=vec[i][2];
        int j=i-1;
        while(j>=0 && vec[j][1]>vec[i][0])
            j--;
        if(j>=0)
            t+=fn(j,vec);
        
        return dp[i]=max(nt,t);
    }
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& p) {
        int n=st.size();
        vector<vector<int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({st[i],et[i],p[i]});
        }
        sort(vec.begin(),vec.end(),[](vector<int>&a,vector<int>&b){return a[1]<b[1];});

        dp.resize(n,-1);
        return fn(n-1,vec);
    }
};