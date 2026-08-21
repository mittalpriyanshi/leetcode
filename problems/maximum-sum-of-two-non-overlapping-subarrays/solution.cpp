class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
       return max(findMax(nums, firstLen, secondLen), 
                        findMax(nums, secondLen, firstLen));
    }
    int findMax(const std::vector<int>& nums, int L, int M) {
        int sumL = 0;
        int sumM = 0;
        for (int i = 0; i < L + M; ++i) {
            if (i < L) {
                sumL += nums[i];
            } else {
                sumM += nums[i];
            }
        }
        int max_L = sumL;
        int max_total = max_L + sumM;
        for (int i = L + M; i < nums.size(); ++i) {
            sumL += nums[i - M] - nums[i - M - L];
            sumM += nums[i] - nums[i - M];
            max_L = max(max_L, sumL);
            max_total = max(max_total, max_L + sumM);
        }
        return max_total;
    }
};