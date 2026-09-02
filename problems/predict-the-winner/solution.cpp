class Solution {
public:
    bool recurse(int turn, int p1Score, int p2Score, int left, int right, vector<int>& nums) {
        if(left > right)
            return p1Score >= p2Score;

        if(!turn) {
            return recurse(1, p1Score + nums[left], p2Score, left + 1, right, nums) ||
                   recurse(1, p1Score + nums[right], p2Score, left, right - 1, nums);
        }

        return recurse(0, p1Score, p2Score + nums[left], left + 1, right, nums) &&
               recurse(0, p1Score, p2Score + nums[right], left, right - 1, nums);
    }

    bool predictTheWinner(vector<int>& nums) {
        return recurse(0, 0, 0, 0, nums.size() - 1, nums);
    }
};