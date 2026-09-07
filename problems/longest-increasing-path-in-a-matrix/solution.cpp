class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    vector<vector<int>> dp;
    int maxLen = INT_MIN;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxLen = INT_MIN;
        dp.assign(m, vector<int>(n, -1)); // length of longest from that cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxLen = max(maxLen, dfs(i, j, matrix, m, n));
            }
        }
        return maxLen;
    }
    int dfs(int i, int j, vector<vector<int>>& matrix, int m, int n) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int bestLen = 1;
        for (int d = 0; d < 4; d++) {
            int nr = i + dir[d];
            int nc = j + dir[d + 1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                matrix[nr][nc] > matrix[i][j]) {
                bestLen =
                    max(bestLen, 1 + dfs(nr, nc, matrix, m, n));
            }
        }
        return dp[i][j] = bestLen;
    }
};