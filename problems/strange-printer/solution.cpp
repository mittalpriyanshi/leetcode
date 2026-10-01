class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        for(int i = 0; i + 1 < n; i++) {
            if(s[i] == s[i+1])
                dp[i][i+1] = 1;
            else
                dp[i][i+1] = 2;
        }

        for(int len = 3; len <= n; len++) {
            for(int l = 0; l + len <= n; l++) {
                int r = l + len - 1;

                // Print s[l] separately
                dp[l][r] = 1 + dp[l+1][r];
                for(int k = l+1; k <= r; k++) {
                    if(s[l] == s[k]) {
                        int middle = (k == l+1) ? 0 : dp[l+1][k-1];
                        dp[l][r] = min(
                            dp[l][r],
                            middle + dp[k][r]
                        );
                    }
                }
            }
        }

        return dp[0][n-1];
    }
};