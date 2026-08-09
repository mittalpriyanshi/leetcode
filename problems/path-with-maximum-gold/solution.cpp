class Solution {
public:
 vector<int> rows = {0,0,-1,1};
 vector<int> cols = {-1,1,0,0};
    int getMaximumGold(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       int maxSum = 0;
       int maxx;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            vector<vector<bool>> vis(m, vector<bool>(n,false));
            if(grid[i][j]!=0){
                vis[i][j]=true;
                maxx = grid[i][j];
                dfs(grid, i,j, vis, grid[i][j],m,n, maxx);
                maxSum = max(maxSum, maxx);
            }
        }
       }
       return maxSum;

    }
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis, int sum,int m, int n, int& maxx){
        for(int k=0;k<4;k++){
            int nr= i+rows[k];
            int nc = j+cols[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]!=0 && !vis[nr][nc]){
                sum+= grid[nr][nc];
                vis[nr][nc]=true;
                dfs(grid,nr,nc,vis,sum,m,n,maxx);
                sum-=grid[nr][nc];
                vis[nr][nc] = false;
            }
        }
        maxx = max(sum,maxx);
        return;
    }
};