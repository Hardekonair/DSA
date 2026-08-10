class Solution {
public:
    int tup[101][101][101];
    int solve(int X,int M,bool alice, vector<int>& piles){
        if(X>=(int)piles.size())
            return 0;

        if(tup[X][M][alice]!=-1){
            return tup[X][M][alice];
        }
        
        int ans;
        if(alice)   ans=-1;
        else    ans=INT_MAX;

        int stones=0;
        for(int i=0;i<(2*M);i++){
            if(X+i<piles.size()){
                stones += piles[X+i] ;
                if(alice)
                    ans = max(ans,stones + solve(X+i+1,max(M,i+1),!alice, piles));
                else
                    ans = min(ans,solve(i+X+1,max(M,i+1),!alice,piles));
            }
        }
        return tup[X][M][alice]=ans;
    }

    int stoneGameII(vector<int>& piles) {
        int M=1;
        bool alice=true;
        int X=0;

        memset(tup,-1,sizeof(tup));
        
        int alice_count=solve(X,M,alice,piles);

        return alice_count;
    }
};