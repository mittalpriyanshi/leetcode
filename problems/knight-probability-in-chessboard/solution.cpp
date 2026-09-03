class Solution {
public:
    vector<int> rows = {-1, -1, 1, 1, -2, -2, 2, 2};
    vector<int> cols = {2, -2, 2, -2, -1, 1, -1, 1};
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k+1,-1.0)));
        return recurse(n,k,row,column,dp);
        
    }
    double recurse(int n, int k, int row, int column,vector<vector<vector<double>>>& dp){
        if(row < 0 || row >= n || column < 0 || column >= n) return 0.0;
        if(k==0) return 1.0;
        if(dp[row][column][k]!=-1.0) return dp[row][column][k];
        double p = 0.0;
        for(int i=0;i<8;i++){
            int newRow = row + rows[i];
            int newCol = column + cols[i];
                p += 0.125 * recurse(n,k-1,newRow,newCol,dp);
        }
        return dp[row][column][k] = p;
    }
};