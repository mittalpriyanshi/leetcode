class Solution {
public:

    vector<int> rows = {1, -1, 0, 0};
    vector<int> cols = {0, 0, 1, -1};

    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int startR = 0;
        int startC = 0;
        int allKeys = 0;

        // Find start and all keys
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    startR = i;
                    startC = j;
                }
                if (grid[i][j] >= 'a' &&
                    grid[i][j] <= 'f') {
                    allKeys |= (1 << (grid[i][j] - 'a'));
                }
            }
        }
        // visited[row][col][keyMask]
        vector<vector<vector<bool>>> visited(
            m,
            vector<vector<bool>>(
                n,
                vector<bool>(64, false)
            )
        );

        queue<tuple<int, int, int>> q;
        q.push({startR, startC, 0});
        visited[startR][startC][0] = true;
        int moves = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [r, c, keyMask] = q.front();
                q.pop();
                if (keyMask == allKeys)
                    return moves;
                for (int i = 0; i < 4; i++) {
                    int nr = r + rows[i];
                    int nc = c + cols[i];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n) {
                        continue;
                    }

                    char tile = grid[nr][nc];
                    // Wall
                    if (tile == '#')
                        continue;

                    // Lock
                    if (tile >= 'A' && tile <= 'F') {
                        int key = tile - 'A';

                        // Don't have the corresponding key
                        if (!(keyMask & (1 << key)))
                            continue;
                    }

                    // Collect key if present
                    int newMask = keyMask;

                    if (tile >= 'a' && tile <= 'f') {
                        int key = tile - 'a';
                        newMask |= (1 << key);
                    }

                    // Already visited this exact state
                    if (visited[nr][nc][newMask])
                        continue;

                    visited[nr][nc][newMask] = true;
                    q.push({nr, nc, newMask});
                }
            }

            moves++;
        }

        return -1;
    }
};