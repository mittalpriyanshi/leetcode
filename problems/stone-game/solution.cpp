class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> dp = piles; 
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                int pickLeft = piles[i] - dp[j];
                int pickRight = piles[j] - dp[j-1];
                
                dp[j] = max(pickLeft, pickRight);
            }
        }
        return dp[n - 1] >= 0;
    
    }
};