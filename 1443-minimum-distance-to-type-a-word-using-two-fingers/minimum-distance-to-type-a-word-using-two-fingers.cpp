class Solution {
public:
    int dp[301][27][27]; // 300 max length, 26 chars + 1 for -1

    int dist(int a, int b) {
        if (a == 26 || b == 26) return 0; // 26 means unused
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int solve(int i, int f1, int f2, string &word) {
        if (i == word.size()) return 0;

        if (dp[i][f1][f2] != -1) return dp[i][f1][f2];

        int curr = word[i] - 'A';

        // Option 1: use finger 1
        int useF1 = dist(f1, curr) + solve(i + 1, curr, f2, word);

        // Option 2: use finger 2
        int useF2 = dist(f2, curr) + solve(i + 1, f1, curr, word);

        return dp[i][f1][f2] = min(useF1, useF2);
    }

    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 26, 26, word); // 26 = no finger placed yet
    }
};