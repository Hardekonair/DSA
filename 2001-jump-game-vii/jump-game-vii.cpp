class Solution {
public:
    int dp[100001];
    bool solve(int i,int minj, int maxj,int n, string &s){
        if(i==n-1)
            return dp[i]=true;
        if(dp[i]!=-1)
            return dp[i];
        for(int k=i+minj;k<=min(i+maxj,n-1);k++){
            if(s[k]=='0'){
                if(solve(k,minj,maxj,n,s))
                    return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool canReach(string s, int minJump, int maxJump) {

        int n=s.size();
        vector<int>ans(n,0);

        ans[0]=1;
        int reachable=0;

        for(int i=1;i<n;i++){
            if(i>=minJump)
                reachable+=ans[i-minJump];
            if(i>maxJump)
                reachable-=ans[i-maxJump-1];
            
            ans[i]=(reachable>0 && s[i]=='0');
        }
        return ans[n-1];
    }
};