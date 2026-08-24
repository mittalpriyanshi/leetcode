class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<unsigned int> dp(target+1,0);
        dp[0]=1; //dp[i] = number of combinations to make sum i
        //going denomination wise, to make sum s, we'll check all denominations first
        for(int i=1;i<=target;i++){
            for(auto num: nums){
                if((i-num) >=0){
                    dp[i] += dp[i-num];
                }
            }
        }
        return dp[target];
    }
};