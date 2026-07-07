class Solution {
public:
    long long sumAndMultiply(int n) {
        string num=to_string(n);
        long long temp=0;
        for(auto it:num){
            if(it!='0'){
                temp=temp*10+(it-'0');
            }
        }
        long long sum=0;
        for(auto it:num){
            if(it!='0')
            sum+=(it-'0');
        }

        return temp*sum;
    }
};