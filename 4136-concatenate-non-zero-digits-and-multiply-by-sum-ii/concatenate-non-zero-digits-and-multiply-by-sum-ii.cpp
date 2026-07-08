class Solution {
public:
    const long long MOD = 1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<long long >pref(n+1), len(n+1), sum(n+1);

        pref[0]=0;
        len[0]=0;
        sum[0]=0;

        for(int i=1;i<=n;i++){
            int d=s[i-1]-'0';

            pref[i]=pref[i-1];
            len[i]=len[i-1];
            sum[i]=sum[i-1];

            if(d!=0){
                pref[i]=(pref[i]*10+d) % MOD;
                len[i]++;
                sum[i]+=d;                
            }
        }

        vector<int>ans;

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        for(auto it:queries){
            int s=it[0]+1, e=it[1]+1;

            int digits = len[e]-len[s-1];

            long long digsum=sum[e]-sum[s-1];

            long long val = (pref[e]-(pref[s-1]*pow10[digits]) % MOD + MOD)%MOD;

            ans.push_back((digsum * val) % MOD);
        }
        return ans;
    }
};