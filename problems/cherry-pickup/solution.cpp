class Solution {
public:
// vector<int> rightDown = {{0,1}, {1,0}};
// vector<int> leftUp = {{0,-1}, {-1,0}};
vector<vector<bool>> vis;
int solve(int i, int j, int n, vector<vector<int>>& grid){
    if(i<0 || i>=n || j<0 || j>=n) return 0;
    vis[i][j] = true;
    if(grid[i][j]==-1) return 0;
   int newcherries = grid[i][j]+ max(solve(i,j+1,n,grid), solve(i+1,j,n,grid));
   if(!vis[n-1][n-1]) return 0;
   return newcherries;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==-1 ||grid[n-1][n-1]==-1 ) return 0;
        vis.assign(n, vector<bool>(n,false));
        return solve(0,0,n,grid);
        
    }
    
};