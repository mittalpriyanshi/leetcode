class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        vector<vector<bool>> dpPal(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (len == 1)
                    dpPal[i][j] = true;
                else if (len == 2)
                    dpPal[i][j] = (s[i] == s[j]);

                else
                    dpPal[i][j] = (s[i] == s[j] && dpPal[i + 1][j - 1]);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            int ans = 1e9;
            for (int end = i; end < n; end++) {

                if (dpPal[i][end]) {

                    ans = min(ans, 1 + dp[end + 1]);
                }
            }

            dp[i] = ans;
        }

        return dp[0] - 1;
    }
};