class Solution {
public:
    int recurseDiff(int left, int right, vector<int>& nums, vector<vector<int>>& memo) {
        if(left == right)
            return nums[left];
            if(memo[left][right]!=INT_MIN) return memo[left][right];
        //curr player minuses the opponents best future score from his current score to see the diff
        int pickLeft = nums[left]- recurseDiff(left+1, right,nums,memo);
        int pickRight = nums[right]- recurseDiff(left, right-1,nums,memo);
        return memo[left][right] = max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, INT_MIN));
        return recurseDiff(0, n - 1, nums, memo)>=0;
    }
};