class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[2] > b[2];
            return a[0] < b[0];
        });
        // sort by start time
        vector<int> suffixMax(
            n); // taaki baad mai jo bhi max values hon, phle hi dikh jayein
        suffixMax[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(events[i][2], suffixMax[i + 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int end = events[i][1];
            // to find first event jiska start> end
            int l = i + 1, h = n - 1;

            int tempIdx = n;
            while (l <= h) {
                int mid = l + (h - l) / 2;
                if (events[mid][0] > end) {
                    tempIdx = mid;
                    h = mid - 1;
                } else
                    l = mid + 1;
            }
            ans = max(ans, events[i][2]);
            if (tempIdx < n)
                ans = max(ans, events[i][2] + suffixMax[tempIdx]);
        }
        return ans;
    }
};
