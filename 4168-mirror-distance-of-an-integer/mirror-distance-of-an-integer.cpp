class Solution {
public:
    int mirrorDistance(int n) {
        int num=n;
        int ans=0;
        while(n){
            int rem=n%10;
            ans=ans*10+rem;
            n=n/10;
        }
        return abs(ans-num);
    }
};