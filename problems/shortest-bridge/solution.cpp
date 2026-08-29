class Solution {
public:
vector<pair<int,int>> dir={{0,1}, {1,0}, {-1,0}, {0,-1}};
    int shortestBridge(vector<vector<int>>& grid) {
        int n= grid.size();
        bool found = false;
        queue<pair<int,int>> q2;
        for(int i=0;i<n;i++){
            if(found) break;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    bfs(i,j,grid,q2);
                    found = true;
                    break;
                } 
            }
        }
        // Phase 2: Multi-source BFS to expand outward and find the second island
        int distance = 0;
        while(!q2.empty()) {
            int size = q2.size();
            // Process the queue level by level to track the distance
            while(size--) {
                auto [r, c] = q2.front();
                q2.pop();
                
                for(int i = 0; i < 4; i++) {
                    int nr = r + dir[i].first;
                    int nc = c + dir[i].second;
                    
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n) {
                        // If we hit the second island, return the current distance
                        if(grid[nr][nc] == 1) {
                            return distance;
                        }
                        // If we hit water, mark it visited (2) and queue it for the next level
                        if(grid[nr][nc] == 0) {
                            grid[nr][nc] = 2;
                            q2.push({nr, nc});
                        }
                    }
                }
            }
            distance++; // Increment distance after expanding one full level outward
        }
        
        return -1;

    }
    void bfs(int i, int j,vector<vector<int>>& grid, queue<pair<int,int>>& q2 ){
        int n = grid.size();
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j]=2;
        q2.push({i,j});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q2.push({r,c});
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+dir[i].first;
                int nc = c+dir[i].second;
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                    q.push({nr,nc});
                    grid[nr][nc]=2;
                }
            }
        }

    }
};