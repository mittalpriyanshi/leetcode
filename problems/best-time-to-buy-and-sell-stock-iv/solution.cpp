class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        return solve(prices, 1,0,k*2,0);
    }
    int solve(vector<int>& prices, int state, int trans, int k, int idx){
        //1 for  buy, 0 for sell
        if(idx == prices.size()) return 0;
        if(trans>k) return 0;
        //buy or skip
        if(state){
            int buy = -prices[idx]+ solve(prices, 0,trans+1, k, idx+1);
            int noBuy = solve(prices, 1, trans, k ,idx+1);
            return max(buy, noBuy);
        }
        //sell or skip
        else{
           int sell = +prices[idx]+ solve(prices, 1,trans+1, k, idx+1);
            int noSell = solve(prices, 0, trans, k ,idx+1);
            return max(sell, noSell);
        }
    }
};