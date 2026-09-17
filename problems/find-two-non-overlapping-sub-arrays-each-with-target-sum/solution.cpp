class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prefix(n, n + 1);
        int l = 0;
        int sum = 0;

        // Find shortest valid subarray ending at or before r
        for (int r = 0; r < n; r++) {
            sum += arr[r];
            while (l <= r && sum > target) {
                sum -= arr[l];
                l++;
            }
            if (r > 0) {
                prefix[r] = prefix[r - 1];
            }
            if (sum == target) {
                prefix[r] = min(prefix[r], r - l + 1);
            }
        }

        int ans = n + 1;

        // Find another subarray after the current one
        l = 0;
        sum = 0;
        for (int r = 0; r < n; r++) {
            sum += arr[r];

            while (l <= r && sum > target) {
                sum -= arr[l];
                l++;
            }

            if (sum == target) {
                int len = r - l + 1;

                // Best subarray completely before l
                if (l > 0 && prefix[l - 1] != n + 1) {
                    ans = min(ans, len + prefix[l - 1]);
                }
            }
        }

        return ans == n + 1 ? -1 : ans;
    }
};