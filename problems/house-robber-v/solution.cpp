class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            bool canrob_both = (i + 1 == n || colors[i] != colors[i + 1]);
            if (canrob_both) // If we can rob both houses, we do it
                dp[i] = nums[i] + dp[i + 1];
            else // If we have to choose, we try both options
                dp[i] = max((long long)nums[i] + dp[i + 2], dp[i + 1]);
        }

        return dp[0];
    }
};