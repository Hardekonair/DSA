class Solution {
public:
    int myAtoi(string s) {
        // if(s.length()==0)
        //     return 0;

        // int i=0;
        // while(i<s.size() && s[i]==' ')           // removing leading spaces
        //     i++;
        
        // int sign=+1;
        // long ans=0;

        // if(s[i]=='-')
        //     sign=-1;

        // i=(s[i]=='+' || s[i]=='-')?i+1:i;

        // for(int j=i;j<s.size();j++){
        //     if(s[j]==' '|| !isdigit(s[j]))
        //         break;
        //     ans=ans*10+(s[j]-'0');
        //     if(sign>0 && ans>INT_MAX)
        //         return INT_MAX;
        //     if(sign<0 && -ans<INT_MIN)
        //         return INT_MIN;

        // }
        
        // return (int)sign*ans;

        int n=s.size();

        int i=0;
        // 1.IGNORING LEADING WHITESPACES
        while(s[i]==' ')
            i++;

        char sign='+';
        // 2.CHECK SIGN
        if(s[i]=='-' || s[i]=='+'){
            // s[i]=='-'?sign='-':sign='+';
            sign=(s[i]=='-'?'-':'+');
            i++;
        }

        //3.SKIPPING LEADING ZEROS
        while(s[i]=='0')
            i++;

        long long num=0;
        for(int j=i;j<n;j++){
            if(!isdigit(s[j])) break;

            int t=s[j]-'0';
            num=num*10+t;
            if(num>INT_MAX){
                if(sign=='-')
                    return INT_MIN;
                return INT_MAX;
            }
        }
        if(sign=='-')
            return 0-num;
        return num;
    }
};