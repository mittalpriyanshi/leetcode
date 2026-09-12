class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> events;
        for (int i = 0; i < n; i++) {
            events.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(events.begin(), events.end());
        vector<int> next(n);
        for (int i = 0; i < n; i++) {
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
            next[i] = idx;
        }
        // dp[c][i] = maximum value using at most c events
        // from i onwards
        vector<vector<long long>> dp(
            5, vector<long long>(n + 1, 0)
        );

        // choice[c][i] = whether we take event i
        vector<vector<bool>> choice(
            5, vector<bool>(n, false)
        );

        for (int c = 1; c <= 4; c++) {
            for (int i = n - 1; i >= 0; i--) {

                // Option 1: DON'T take event i
                dp[c][i] = dp[c][i + 1];

                // Option 2: TAKE event i
                long long take = events[i][2];

                if (next[i] < n) {
                    take += dp[c - 1][next[i]];
                }

                if (take > dp[c][i]) {
                    dp[c][i] = take;
                    choice[c][i] = true;
                }
            }
        }

        // Reconstruct 
        vector<int> ans;

        int c = 4;
        int i = 0;

        while (i < n && c > 0) {

            if (choice[c][i]) {
                // We took event i
                ans.push_back(events[i][3]);

                i = next[i];
                c--;
            }
            else {
                // We didn't take event i
                i++;
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};