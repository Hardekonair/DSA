class Solution {
public:
    int rotatedDigits(int n) {
        unordered_map<int,int>mpp;
        // mpp[0]=0;
        // mpp[1]=1;
        // mpp[8]=8;
        mpp[2]=5;
        mpp[5]=2;
        mpp[6]=9;
        mpp[9]=6;

        int ans=0;
        for(int i=1;i<=n;i++){
            int temp=i;
            bool f=false;
            while(temp){
                int rem=temp%10;
                temp/=10;
                if(mpp.find(rem)!=mpp.end()){
                    f=true;
                }
                if(rem==3 || rem==4 || rem==7){
                    f=false;
                    break;
                }
            }
            if(f)
                ans++;
        }
        return ans;

    }
}; 