class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        for (int c = 1; c <= k; c++) {
            for (int i = n - 1; i >= 0; i--) {

                // Don't pick event i
                dp[c][i] = dp[c][i + 1];

                // Find first event with start > current end
                int low = i + 1;
                int high = n - 1;
                int idx = n;

                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if (events[mid][0] > events[i][1]) {
                        idx = mid;
                        high = mid - 1;
                    }
                    else {
                        low = mid + 1;
                    }
                }

                // Pick event i
                int take = events[i][2] + dp[c - 1][idx];
                dp[c][i] = max(dp[c][i], take);
            }
        }
        return dp[k][0];
    }
};