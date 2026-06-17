class Solution {
public:
    char processStr(string s, long long k) {
        long long len=0;
        for(auto it:s){
            if(isalpha(it))
                len++;
            else if(len>0 && it=='*')
                len--;
            else if(it=='#')
                len=len+len;
            else if(it=='%')    
                continue;
            
        }
        if(k>=len)
            return '.';

        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='*')
                len++;
            else if(s[i]=='%')
                k=len-k-1;
            else if(s[i]=='#'){
                len=len/2;
                k=k>=len?k%len:k;
            }
            else
                len--;
            
            if(len==k)  
                return s[i];
        }
        return '.';
    }
};