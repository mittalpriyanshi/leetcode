class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int> dp(n, 0);
        for(int i=0;i<n;i++){
            if(dp[i]==0) dp[i]=solve(i,d,arr,dp);
        }
        return *max_element(dp.begin(), dp.end());
    }
    int solve(int idx, int d, vector<int>& arr, vector<int>& dp){
        if(dp[idx]!= 0) return dp[idx];
        int ans = 0;
        for(int j=1;j<=d;j++){
            if(idx+j < arr.size() && arr[idx+j]>=arr[idx]) break;
            else if(idx+j < arr.size() && arr[idx+j]<arr[idx]){
                ans = max(ans, solve(idx+j, d,arr,dp));
            }
        }
        for(int j=1;j<=d;j++){
            if(idx-j >=0 && arr[idx-j]>=arr[idx]) break;
            if(idx-j>=0 && arr[idx-j]<arr[idx]){
                ans = max(ans, solve(idx-j, d,arr,dp));
            }

        }
        return dp[idx]= 1+ ans;
    }
};