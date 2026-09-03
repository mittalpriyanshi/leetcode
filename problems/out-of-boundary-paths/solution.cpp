class Solution {
public:
vector<int> dirs = {0,1,0,-1,0};
long long MOD = 1e9+7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(maxMove+1, -1)));
        return recurse(m,n,0,maxMove,startRow, startColumn, dp);
        //number of moves if on dp[r][c][k]
    }
    long long recurse(int m, int n, int k, int maxMove, int r, int c, vector<vector<vector<long long>>>& dp){
        if(r<0 || r>=m || c<0 || c>= n) return 1;
        if(k==maxMove) return 0;
        if(dp[r][c][k]!=-1) return dp[r][c][k]%MOD;
        long long tempVal=0;
         for(int i=0;i<4;i++){
            tempVal =(tempVal + recurse(m,n,k+1,maxMove,r+dirs[i], c+dirs[i+1],dp))%MOD;
        }
        dp[r][c][k] = tempVal;
        return dp[r][c][k] % MOD;
    }
};