class Solution {
public:
    // vector<vector<vector<long long>>>dp;
    map<string,int>dp;
    long long countk(int i,int c2,int c3,int c5,vector<vector<int>>& factors,vector<int>& target){
        // if(c2<-20 || c2>20 || c3<-20 || c3>20 || c5<-20 || c5>20)
        //    return 0;
        if(i==factors.size()){
            if(c2==target[0] && c3==target[1] && c5==target[2]){
                return 1;
            }
            return 0;
        }
        string key=to_string(i)+","+to_string(c2)+","+to_string(c3)+","+to_string(c5);
        if(dp.find(key)!=dp.end())
                return dp[key];
        
        return dp[key]=
                countk(i+1,c2+factors[i][0],c3+factors[i][1],c5+factors[i][2],factors,target)+
                countk(i+1,c2,c3,c5,factors,target)+
                countk(i+1,c2-factors[i][0],c3-factors[i][1],c5-factors[i][2],factors,target);
    }

    
    int countSequences(vector<int>& nums, long long k) {
        int n=nums.size();

        // dp.resize(101,
        //             vector<vector<long long>>(63,
        //               vector<long long>(43,-1)));
        
        vector<vector<int>>factors(n,vector<int>(3));
        for(int i=0;i<n;i++){
            int x=nums[i];
            int c2=0,c3=0,c5=0;
            while(x%2==0){
                c2++;
                x/=2;
            }
            while(x%3==0){
                c3++;
                x/=3;
            }
            while(x%5==0){
                c5++;
                x/=5;
            }
            factors[i]={c2,c3,c5};
        }
        vector<int>target(3);
        long long x=k;
            int c2=0,c3=0,c5=0;
            while(x%2==0){
                c2++;
                x/=2;
            }
            while(x%3==0){
                c3++;
                x/=3;
            }
            while(x%5==0){
                c5++;
                x/=5;
            }
            if(x!=1)    return 0;    // k contains factors other than 2,3,5 which can't be acheived
            target={c2,c3,c5};
        
        return countk(0,0,0,0,factors,target);
    }
};
// int dp[19][80][40][40] {};
// constexpr int OFFSET = 20;
// class Solution {
// public:
//     int countSequences(vector<int>& nums, long long k) {
//         int n = nums.size();
//         vector<int> ap2(n), ap3(n), ap5(n);

//         for(int i = 0; i < n; i++) {
//             while(nums[i] % 2 == 0) ap2[i]++, nums[i] /= 2;
//             while(nums[i] % 3 == 0) ap3[i]++, nums[i] /= 3;
//             while(nums[i] % 5 == 0) ap5[i]++, nums[i] /= 5;
//         }
        
//         int tp2 = 0, tp3 = 0, tp5 = 0;
//         while(k % 2 == 0) tp2++, k /= 2;
//         while(k % 3 == 0) tp3++, k /= 3;
//         while(k % 5 == 0) tp5++, k /= 5;
//         if(k != 1) return 0;

//         auto go = [&](this auto&& go, int i, int p2, int p3, int p5) -> int {
//             if(i == n) return (p2-OFFSET == tp2 && p3-OFFSET == tp3 && p5-OFFSET == tp5);
//             if(dp[i][p2][p3][p5] != -1) return dp[i][p2][p3][p5];
//             return dp[i][p2][p3][p5] =
//                 go(i + 1, p2, p3, p5) +
//                 go(i + 1, p2 + ap2[i], p3 + ap3[i], p5 + ap5[i]) +
//                 go(i + 1, p2 - ap2[i], p3 - ap3[i], p5 - ap5[i]);
//         };
//         memset(dp, -1, sizeof(dp));
//         return go(0, OFFSET+0, OFFSET+0, OFFSET+0);
//     }
// };