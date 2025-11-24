class Solution {
public:
    bool isvalid(string a,string b){
        if(a.size()+1!=b.size())
            return false;
        int i=0,j=0,count=0;
        while(i<a.size()){
            if(a[i]==b[j]){
                i++;j++;
            }
            else{
                j++;count++;
            if(count>1)
                return false;
            }
        }
        return true;
    }

    static bool comp(string &a,string &b){         // FOR SORTING STRING IN INCREASING ORDER OF THEIR LENGTH
        return a.size()<b.size();
    }

    int longestStrChain(vector<string>& words) {
        int n=words.size();
    
        sort(words.begin(),words.end(),comp);

        int maxlen=1;
        vector<int> dp(words.size(),1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(isvalid(words[j],words[i])){
                    dp[i]=max(dp[j]+1,dp[i]);
                }
            }
            if(dp[i]>maxlen)
                maxlen=dp[i];
        }
        return maxlen;
    }   
};