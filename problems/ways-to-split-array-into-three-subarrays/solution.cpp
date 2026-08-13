class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        long long ans = 0;
        int j = 1, k = 1;

        for (int i = 0; i < n - 2; i++) {

            // j must be at least i+1
            j = max(j, i + 1);

            // Find first j such that leftSum <= midSum
            while (j < n - 1 &&
                   prefix[j] - prefix[i] < prefix[i]) {
                j++;
            }

            // k should never be behind j
            k = max(k, j);

            // Find first k where midSum > rightSum
            while (k < n - 1 &&
                   prefix[k] - prefix[i] <= prefix[n - 1] - prefix[k]) {
                k++;
            }

            ans += (k - j);
            ans %= MOD;
        }

        return ans;
    }
};