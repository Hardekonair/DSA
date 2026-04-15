class Solution {
public:
    int closestTarget(vector<string>& words, string target, int s) {
        int ans=-1;
        int n=words.size();
        if(words[s]==target)   return 0;
        int i=s,j=s;
        int nxt=((i+1)%n);i++;
        int prev=(j-1+n)%n;j--;

        while(i-j<=n){
            if(words[nxt]==target) return abs(i-s);
            if(words[prev]==target) return abs(s-j);
            nxt=(nxt+1)%n;i++;
            prev=(prev-1+n)%n;j--;
        }
        return -1;
    }
};