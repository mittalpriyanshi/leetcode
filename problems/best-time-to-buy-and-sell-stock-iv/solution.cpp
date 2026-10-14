class Solution {
public:

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k*2+1, vector<int>(2,-1)));
        return solve(prices, 1,0,k*2,0,dp);
    }
    int solve(vector<int>& prices, int state, int trans, int k, int idx, vector<vector<vector<int>>>& dp){
        //1 for  buy, 0 for sell
        if(idx == prices.size()) return 0;
        if(trans>k) return 0;
        if(dp[idx][trans][state]!=-1) return dp[idx][trans][state];
        //buy or skip
        if(state){
            int buy = -prices[idx]+ solve(prices, 0,trans+1, k, idx+1, dp);
            int noBuy = solve(prices, 1, trans, k ,idx+1, dp);
            return dp[idx][trans][state]= max(buy, noBuy);
        }
        //sell or skip
        else{
           int sell = +prices[idx]+ solve(prices, 1,trans+1, k, idx+1, dp);
            int noSell = solve(prices, 0, trans, k ,idx+1, dp);
            return dp[idx][trans][state]= max(sell, noSell);
        }
    }
};