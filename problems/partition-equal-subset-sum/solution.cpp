class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int &x:nums) total+=x;
        if(total & 1) return false;
        vector<vector<int>> dp(n+1, vector<int>((total/2) +1 , -1));
        return solve(total/2,0,nums,dp);
    }
    bool solve(int target, int i, vector<int>& nums,vector<vector<int>>& dp){
        if(target==0) return true;
        if(i>=nums.size() || target<0) return false; 
        if(dp[i][target]!=-1) return dp[i][target];
       return dp[i][target] = solve(target-nums[i],i+1,nums,dp) || solve(target,i+1,nums,dp);
       
    }
};