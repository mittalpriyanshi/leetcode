class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,INT_MIN);
        //top down
        dp[0]=nums[0];
        dp[1]= dp[0]+nums[1];
        for(int i=2;i<n;i++){
            for(int j=i-1;j>=i-k && j>=0;j--){
                dp[i]=max(nums[i]+dp[j], dp[i]);
            }
        }
        return dp[n-1];
    }
    
};