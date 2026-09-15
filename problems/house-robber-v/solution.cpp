class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        long long dp[n + 1];
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 1; i < n; i++) {
            if (colors[i] != colors[i - 1]) {
                dp[i + 1] = dp[i] + nums[i];
            } else {
                dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
            }
        }
        return dp[n];
    }
};