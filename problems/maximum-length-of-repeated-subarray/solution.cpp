class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        if(nums1[0]==nums2[0]) dp[0][0]=1;
        for(int j=1;j<m;j++){
            if(nums1[0]==nums2[j]) dp[0][j]=1+dp[0][j-1];
            else dp[0][j]=dp[0][j-1];
        }
        for(int i=1;i<n;i++){
            if(nums1[i]==nums2[0]) dp[i][0]=1+dp[i-1][0];
            else dp[i][0]=dp[i-1][0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(nums1[i]==nums2[j]) dp[i][j]= dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};