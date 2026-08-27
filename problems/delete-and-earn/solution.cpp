class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int peak = *max_element(nums.begin(), nums.end());
        vector<int> dp(peak+1,0);
        for(int a:nums){
            dp[a]+=a;
        }
        dp[0]=0;
        dp[1]=max(dp[0], dp[1]);
        for(int i=2;i<=peak;i++){
            dp[i]=max(dp[i-2]+dp[i], dp[i-1]);
        }
        return dp[peak];
    }
};