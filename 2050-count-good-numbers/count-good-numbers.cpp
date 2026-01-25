class Solution {
public:
const long long m = 1000000007LL;

long long powmod(long long x, long long n){
    x %= m;
    if(n==0) return 1;
    if(n==1) return x;

    if(n%2==0)
        return powmod((x*x)%m, n/2);

    return (x * powmod((x*x)%m, n/2)) % m; // n=2k+1
}

int countGoodNumbers(long long n) {
    long long odd  = n/2;
    long long even = (n+1)/2;

    return (int)((powmod(5, even) * powmod(4, odd)) % m);
}

};