class Solution {
public:
    int m, n;
    vector<vector<int>> visited;
    bool dfs(vector<vector<char>>& grid, int r, int c, int pr, int pc,
             char ch) {
        visited[r][c] = 1;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;
            if (grid[nr][nc] != ch)
                continue;
            // ignore if parent
            if (nr == pr && nc == pc)
                continue;
            if (visited[nr][nc])
                return true;
            if (dfs(grid, nr, nc, r, c, ch))
                return true;
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1, grid[i][j]))
                        return true;
                }
            }
        }
        return false;
    }
};