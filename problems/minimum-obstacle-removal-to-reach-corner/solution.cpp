class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        vector<int> dir={0,1,0,-1,0};
        vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        deque<pair<int,int>> dq;
        dist[0][0]=0;
        vis[0][0]=true;
        dq.push_front({0,0});
        while(!dq.empty()){
            auto [r,c]= dq.front();
            dq.pop_front();
            for(int i=0;i<4;i++){
                int nr = r+dir[i];
                int nc = c+dir[i+1];
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    if(!vis[nr][nc]){
                         if(grid[nr][nc]==1){
                            dist[nr][nc]=dist[r][c]+1;
                            dq.push_back({nr,nc});
                         }
                         else{
                            dist[nr][nc]=dist[r][c];
                            dq.push_front({nr,nc});
                         }
                         vis[nr][nc]=true;
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};