/**
 * @param {string} s
 * @param {number} k
 * @return {character}
 */
var processStr = function(s, k) {
    let len=0;
    for(let ch of s){
        if(/[a-z]/.test(ch))
            len++;
        else if(len>0 && ch=='*')
            len--;
        else if(ch=='#')
            len=len+len;
        // else if(ch=='%')
        //     continue;
    }

    if(k>=len)
        return '.';
    
    for(let i=s.length-1;i>=0;i--){
        if(s[i]=='*')
            len++;
        else if(s[i]=='#'){
            len=len/2;
            k=k>=len?k%len:k;
        }
        else if(s[i]=='%')
            k=len-k-1;
        else
            len--;
        
        if(len==k)
            return s[i];
    }
    return '.';
};