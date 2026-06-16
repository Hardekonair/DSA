/**
 * @param {string} s
 * @return {string}
 */
var processStr = function(s) {
    let ans="";
    for(let c of s){
        if(/[a-z]/.test(c))
            ans+=c;
        else if(ans.length>0 && c=='*')
            ans=ans.slice(0,-1);
        else if(c=='#')
            ans=ans+ans;
        else if(c=='%')
            ans=ans.split('').reverse().join('');
    }
    return ans;
};