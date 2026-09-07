class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    //vector<vector<int>> dp;
    int maxLen = INT_MIN;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
       // dp.assign(m, vector<int>(n, 0)); // length of longest from that cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<bool>> vis(m, vector<bool>(n, false));
                vis[i][j]=true;
                dfs(i, j, matrix, m, n,1, vis);
            }
        }
        return maxLen;
    }
    void dfs(int i, int j, vector<vector<int>>& matrix, int m, int n, int currLen, vector<vector<bool>> vis) {
        for (int d = 0; d < 4; d++) {
            int nr = i + dir[d];
            int nc = j + dir[d + 1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && matrix[nr][nc]> matrix[i][j]) {
                    vis[nr][nc]=true;
                    dfs(nr,nc,matrix,m,n,currLen+1, vis);

            }
        }
        maxLen = max(maxLen, currLen);
    }
};