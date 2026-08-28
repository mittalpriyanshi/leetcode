class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2));

        //Base case
        dp[n][0] = 0; dp[n][1] = 0;

        //You can also skip typing the above base case by directly assigning every element of dp as 0 like below
        //vector<vector<int>> dp(n + 1, vector<int>(2, 0));


        //Explore all paths (bottom-up)
        for(int idx = n - 1; idx >= 0; idx--) {
            for(int canBuy = 1; canBuy >= 0; canBuy--) {
                //Observe that this block is same as memoization
                int buy = -1e9, sell = -1e9;
                if(canBuy) {
                    buy = -prices[idx] + dp[idx + 1][!canBuy];
                } else {
                    sell = prices[idx] - fee + dp[idx + 1][!canBuy];
                }
                int move_on = dp[idx + 1][canBuy];
                dp[idx][canBuy] = max({buy, sell, move_on});                
            }
        }

        //idx = 0 and canBuy = true is the initial state
        return dp[0][1];
    }
};