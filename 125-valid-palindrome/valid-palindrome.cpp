class Solution {
public:
    bool isPalindrome(string s) {
                                     //optimal approach
    int l = 0, r = s.size() - 1;
    while (l <= r) {
        if (!isalnum(s[l])) {
            l++;
        } 
        else if(!isalnum(s[r])) {
            r--;
        } 
        else {
            if(tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++;
            r--;
        }
    }
    return true;
                                     //brute approach
        // string s1;
        // for(auto it:s)
        //     if(isalnum(it))
        //         s1+=tolower(it);

        // int n=s1.size();
        // for(int i=0;i<n/2;i++){
        //     // if(i<=n-i-1){
        //         if(s1[i]!=s1[n-i-1])
        //             return false;
        //     // }
        // }
        // return true;
    }
};