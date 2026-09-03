class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 1);
        vector<int> ways(n, 1);
        int maxLength = 1;
        dp[0]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[j]+1 > dp[i] ){
                    dp[i] = dp[j]+1;
                    ways[i]=ways[j];
                }
                else if (dp[j] + 1 == dp[i]) {
                    ways[i] += ways[j]; // Add j's ways to our total ways
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxLength) count+=ways[i];
        }
        return count;
    }
};