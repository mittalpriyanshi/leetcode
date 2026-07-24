class Solution {
public:

    int minCut(string s) {
        int n =s.size();
        vector<int> dp(n, -1);
        vector<vector<bool>> dpPal(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {

            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                if (len == 1)
                    dpPal[i][j] = true;

                else if (len == 2)
                    dpPal[i][j] = (s[i] == s[j]);

                else
                    dpPal[i][j] = (s[i] == s[j] && dpPal[i + 1][j - 1]);
            }
        }
        return solve(s,0, dp, dpPal)-1;
    }
    bool isPalind(string& s, int l, int r ){
        while(l<r) {
            if(s[l++]!=s[r--]) return false;
        }
        return true;
    }
    int solve(string s, int i, vector<int>& dp, vector<vector<bool>>& dpPal){
        int ans= INT_MAX;
        if(i==s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        for(int end =i;end<s.size();end++){
            if (dpPal[i][end]){
                ans = min(ans, 1+ solve(s,end+1,dp,dpPal));
            }
        }
        return dp[i] = ans;

    }
};