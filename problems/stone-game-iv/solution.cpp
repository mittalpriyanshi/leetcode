class Solution {
public:
    bool winnerSquareGame(int n) {
        if (n == 1)
            return true;
        if (n == 2)
            return false;
        int q = sqrt(n);
        if (q * q == n)
            return true;
        vector<bool> dp(n + 1, false);
        dp[0] = false;
        for (int i = 1; i <= n; i++) {
            for (int x = 1; x * x <= i; x++) {
                if (!dp[i - (x * x)]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};