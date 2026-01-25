class Solution {
public:
    // double myPow(double x, int n) {
    //     long long N=n;    // long long is used when n=INT_MIN but -INT_MIN is not in range
    //     if(N<0){
    //         x=1/x;
    //         N=-N;
    //     }
    //     if(N==0)
    //         return 1.0;
        
    //     if(N==1)
    //         return x;
        
    //     if(N%2==0)
    //     return myPow(x*x,N/2);
    //     else
    //     return x*myPow(x*x,(N-1)/2);
    // }

    double myPow(double x, int n) {
        long long N=n;
        double ans=1; 

        if(x==-1)
            return (n%2)?x:-x;
        if(x==1)    
            return x;

        if(N<0){
            x=1/x;
            N=-N;
        }
        while(N>0){
            if(N & 1)
                ans*=x;
            x*=x;
            N/=2;
        }
        return ans;
    }
};