class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int> prefix(n);
        prefix[0]=stones[0];
        for(int i=1;i<n;i++){
            prefix[i]=stones[i]+prefix[i-1];
        }
        vector<int> dp(n,0);  // dp[i]= max difference alice can get if she picks from ith stones at first
        dp[n-1]= prefix[n-1];
        dp[n-2] = max(prefix[n-1], prefix[n-2] - prefix[n-1]);
        for(int i=n-3;i>=1;i--){
            int diff_take = prefix[i]-dp[i+1];
            int notTake= dp[i+1];
            dp[i]=max(diff_take, notTake);
        }
        return dp[1];
    }
};