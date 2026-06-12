class Solution {
public:
    // bool solve(int i,int j,string s, string p){
    //     if(j==p.size()){
    //         return i==s.size();
    //     }
    //     if(i==s.size()){
    //         while(j+1<p.size() && p[j+1]=='*')
    //             j+=2;
    //         return j==p.size();
    //     }

    //     if(j+1<p.size() && p[j+1]=='*'){
    //         bool take=false;
    //         if(p[j]=='.' || p[j]==s[i])
    //             take = solve(i+1,j,s,p);
    //         bool nottake = solve(i,j+2,s,p);
            
    //         return take || nottake;
    //     }
    //     else{
    //         if(p[j]=='.' || p[j]==s[i])
    //             return solve(i+1,j+1,s,p);
    //     }
    //     return false;
    // }
    bool solve(int i,int j,string s, string p){
        vector<vector<bool>>dp(s.size()+1,vector<bool>(p.size()+1,false));

        // if(j==p.size()){
        //     return i==s.size();
        // }
        dp[s.size()][p.size()]=true;    // empty string empty pattern

        // if(i==s.size()){
        //     while(j+1<p.size() && p[j+1]=='*')
        //         j+=2;
        //     return j==p.size();
        // }
        for(int j=p.size()-1;j>=0;j--){
            if(j+1<p.size() && p[j+1]=='*')
                dp[s.size()][j]=dp[s.size()][j+2];
        }

        for(int i=s.size()-1;i>=0;i--){
            for(int j=p.size()-1;j>=0;j--){
                if(j+1<p.size() && p[j+1]=='*'){
                    bool take=false;
                    if(p[j]=='.' || p[j]==s[i])
                        take = dp[i+1][j];
                    bool nottake = dp[i][j+2];
                    
                    dp[i][j]= take || nottake;
                }
                else{
                    if(p[j]=='.' || p[j]==s[i])
                        dp[i][j]= dp[i+1][j+1];
                }
                
            }
        }
        return dp[0][0];
    }
    bool isMatch(string s, string p) {
        return solve(0,0,s,p);
        
    }
};