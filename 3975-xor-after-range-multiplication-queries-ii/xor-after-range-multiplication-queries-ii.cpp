class Solution {
public:
    int M=1e9+7;
    long long power(long long a,long long b){
        long long res=1;
        while(b){
            if( b&1 ) 
                res=(res*a)%M;
            a=(a*a)%M;
            b>>=1;
        }
        return res;
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int blocksize=sqrt(n);

        unordered_map<int,vector<vector<int>>>smallQueries; // STORING QUERIES WITH SAME SMALL 'K' 

        //  SEPARATE QUERIES
        for(auto &q:queries){
            int L=q[0],R=q[1],K=q[2],V=q[3];

            if(K>=blocksize){
                // Large K=> direct update
                for(int i=L;i<=R;i+=K){
                    nums[i]=(1LL*nums[i]*V)%M;
                }
            }
            else{
                //  Small K -> Store for later
                smallQueries[K].push_back(q);
            }
        }
        // PROCESS SMALL QUERIES OF SAME 'K'
        for(auto &[K,qList]:smallQueries){

            // DIFF ARRAY (multiplicative)
            vector<long long>diff(n,1);

            for(auto &q:qList){
                int L=q[0],R=q[1],V=q[3];

                // Start multiplying from L
                diff[L]=(diff[L]*V)%M;

                // Find where effect should stop
                int steps = (R-L)/K;
                int next = L+(steps+1)*K;

                // STOP EFFECT USING MODULAR INVERSE
                if(next<n){
                    long long inv=power(V,M-2);
                    diff[next]=(diff[next]*inv)%M;
                }
            }

            // BUILD CUMULATIVE PRODUCT IN DIFF BY JUMPING K
            for(int i=0;i<n;i++){
                if(i-K>=0){
                    diff[i]=(diff[i]*diff[i-K])%M;
                }
            }

            //APPLY TO ORG ARRAY
            for(int i=0;i<n;i++){
                nums[i]=(1LL* nums[i]*diff[i])%M;
            }
        }
        int res=0;
        for(int x:nums){
            res^=x;
        }
        return res;
    }
};