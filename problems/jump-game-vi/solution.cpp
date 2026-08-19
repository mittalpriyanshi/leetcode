class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,INT_MIN); //dp[i]=max score to reach end from index i
        //top down
        // dp[0]=nums[0];
        // dp[1]= dp[0]+nums[1];
        // for(int i=2;i<n;i++){
        //     for(int j=i-1;j>=i-k && j>=0;j--){
        //         dp[i]=max(nums[i]+dp[j], dp[i]);
        //     }
        // }
        // return dp[n-1];
        dp[0]=nums[0];
        multiset<int> s;
        s.insert(dp[0]);
        for(int i = 1; i < size(nums); i++) {
        if(i > k) s.erase(s.find(dp[i - k - 1]));  // erase elements from which we cant jump to current index
        s.insert(dp[i] = *rbegin(s) + nums[i]);    // choose element with max score and jump from that to the current index
    }
	return dp[n-1];
    }
    
};