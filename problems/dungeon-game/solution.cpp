class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        //dp[i][j] = minimum energy needed to enter cell[i][j]
        dp[m-1][n-1] = dungeon[m-1][n-1] >=0 ? 1 : abs(dungeon[m-1][n-1])+1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;
                int need = INT_MAX;
                if(i+1<m) need = min(need, dp[i+1][j]);
                if(j+1 <n) need = min(need, dp[i][j+1]);
                dp[i][j] = max(1, need - dungeon[i][j]);
            }
        }
        return dp[0][0];
    } 
};