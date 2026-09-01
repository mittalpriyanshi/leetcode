class Solution {
public:
int ans=0;
vector<int> dir = {0,1,0,-1,0};
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int startRow, startCol;
        long long mask = 0;
        for(int i = 0; i < m; i++)
         for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) startRow = i, startCol = j;
                if(grid[i][j] != -1) mask |= 1 << i*n+j;       // unn bits ko 1 krdo jo humko visit krni hai and jb hum visit krlenge toh we'll unmark them, last m check krne k liye whether it becomes 0 or not
            }
            dfs(startRow, startCol, mask, grid);
            return ans;

    }
    void dfs(int i, int j, long long mask, vector<vector<int>>& grid){
        int m = grid.size();
        int n=grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==-1 || (mask&(1<<i*n+j))==0) return;
        mask = mask ^ (1<<i*n+j);
        if(grid[i][j]==2){
            if(!mask) ans++;
            return;
        }
        for(int d=0;d<4;d++){
            dfs(i+dir[d], j+dir[d+1], mask, grid);
        }
    }
};