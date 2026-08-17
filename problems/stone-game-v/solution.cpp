class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n);
        prefix[0] = stoneValue[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = stoneValue[i] + prefix[i - 1];
        }
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(0, n - 1, prefix, dp);
        
    }
    int solve(int start, int end, vector<int>& prefix, vector<vector<int>>& dp) {
        if(start>=end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int score =0;
        for (int mid = start; mid < end; mid++) {
           int sumleft = prefix[mid] - (start > 0 ? prefix[start - 1] : 0);
            int sumright = prefix[end] - prefix[mid];
            
        if(sumleft > sumright){
            //[start....mid | mid+1...end]
            score = max(score, sumright + solve(mid+1,end,prefix,dp));
        }
        else if(sumleft < sumright){
            score = max(score, sumleft + solve(start,mid,prefix,dp));
        }
        else{
            score = max({score, sumleft + solve(start, mid, prefix,dp),
                             sumright + solve(mid + 1, end, prefix,dp)});
        }
        }
        
        return dp[start][end]=score;
    }
};