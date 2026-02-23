class Solution {
public:
                                    // BRUTE - TLE
    string binaryf(int x,int k){
        string ans="";
        while(x>0){
            ans+=x%2+'0';       // TO CONVERT DECIMAL NUMBER GATEHERED FROM MOD INTO CHAR
            x/=2;
        }
        while(ans.size()<k){    // PADDING
            ans+='0';
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
    bool hasAllCodes1(string s, int k) {
        int n=s.size();

        unordered_map<string,int>mpp;
        for(int i=0;i<(1<<k);i++){
            mpp[binaryf(i,k)]=1;
        }
        int i=0,j=k-1;
        while(i<n-k+1){
            string key=s.substr(i,k);
            mpp[key]=0;
            i++;
        }
        for(auto it:mpp){
            if(mpp[it.first]==1)
                return false;
        }
        return true;

    }

    // INTUTION - FLAW OF ABOVE CODE - YOU DON'T NEED TO GENERATE ALL BINARY STRING AND MATCH IT FEOM THE EXISTING
    // INSTEAD - YOU CAN CHECK HOW MANY DISTINCT BINARY STRING OF SIZE K EXIST AND MATCH IT WITH TOTAL NUMBER OF BINARY STRING
    // RESULT - IF THEY ARE EQUAL RETURN TURE ELSE RETURN FALSE

    bool hasAllCodes(string s, int k) {
        int n=s.size();
        unordered_set<string>st;
        int i=0;
        while(i<n-k+1){
            string key=s.substr(i,k);
            st.insert(key);
            i++;
        }
        if(st.size()==(1<<k))
            return true;
        return false;
    }


};