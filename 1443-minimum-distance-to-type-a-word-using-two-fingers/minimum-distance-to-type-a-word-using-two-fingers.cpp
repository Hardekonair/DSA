class Solution {
public:
    int dist1(int a,int b){
        if(a==26 || b==26)  // 26 means finger is not on any char i.e in air
            return 0;
        int x1=a/6, y1=a%6;
        int x2=b/6 , y2=b%6;

        return abs(x1-x2)+abs(y1-y2);
    }

    int dp[301][27][27];    // 300 max length, 26 chars + 1 for -1
    
    int solve1(int i,string word,int h1,int h2){
        if(i==word.size())  return 0;

        if(dp[i][h1][h2]!=-1)
            return dp[i][h1][h2];
        
        int curr=word[i]-'A';

        //option 1: use hand one
        int hand1=dist1(h1,curr)+solve1(i+1,word,curr,h2);
    
        //option 2: use hand two
        int hand2=dist1(h2,curr)+solve1(i+1,word,h1,curr);

        return dp[i][h1][h2]=min(hand1,hand2);
    }
    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve1(0,word, 26, 26); // 26 = no finger placed yet        
    }
};