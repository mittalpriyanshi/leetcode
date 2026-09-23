class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //max iterations to make side element sum equal to 5
        int n= nums.size();
        long long sum= accumulate(nums.begin(), nums.end(),0);
        long long k= sum-x;
        if (k < 0) return -1;
        if (k == 0) return n;

        long long best = -1, i = 0, res = 0;
        for (int j = 0; j < n; j++) {
            res += nums[j];
            while (res > k)
                res -= nums[i++];

            if (res == k)
                best = max(best, j - i + 1);
        }

        return best + 1 ? n - best : -1;
    }
};