class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        if(n==1) return piles[0];
        if(n==2) return piles[0]+piles[1];
        // M max is X max 
        int m=1;
        vector<vector<int>> dp(n, vector<int>(n,-1));
        vector<int> suffixSum(n); // mereko sum chaiye remaining jisme se mai choose kr skti hu, so like suffixsum, totalremaining - bob ka best pick
        suffixSum[n-1] = piles[n-1];
        for(int i=n-2;i>=0;i--) suffixSum[i] = piles[i]+suffixSum[i+1];
        return solve(piles,dp,suffixSum,0,m);

    }
    int solve(vector<int>& piles,vector<vector<int>>& dp,vector<int>& suffixSum, int i,int M){
        if(i>=piles.size()) return 0;
         if (i + 2 * M >= piles.size()) return suffixSum[i]; 
        if(dp[i][M]!=-1) return dp[i][M];
        int res=0;
        for(int x=1; x<=(2*M) && i + x <= piles.size();x++){
            //alice can take from i to i+x-1
            //then bob can take from i+x , then i will have remaining - bob ka liya hua to take and i want to maximise it
            // dp[i][m] = max(current + remainingafterTaken - bob ka liya hua ) 
            res = max(res, suffixSum[i]-solve(piles,dp,suffixSum,i+x,max(M,x)) );
        }
        dp[i][M] = res;
        return res;
    }
};