class Solution {
public:
int dp[101][101][101];
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        //dp state - dp[l][r][k]
        //Maximum score we can obtain from boxes[l...r], assuming there are already k boxes of the same color as boxes[l] attached immediately to its left.
        memset(dp, -1, sizeof(dp));
        return solve(boxes,0,n-1,0);

    }
    int solve(vector<int>& boxes, int l, int r, int k){
        if(l>r) return 0;
        if(dp[l][r][k]!=-1) return dp[l][r][k];
        int ans = (k+1)*(k+1) + solve(boxes, l+1, r, 0);
        for(int m=l+1;m<=r;m++){
            if(boxes[m]== boxes[l]){
                //same color
               ans = max(ans, solve(boxes, l+1, m-1, 0)+ solve(boxes,m,r,k+1));
            }
        }
        return dp[l][r][k] = ans;
    }
};