class Solution {
public:
    long long MOD = 1e9 + 7;
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        if (n == 3 && nums[0] == nums[1] && nums[1] == nums[2])
            return 1;
        vector<long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i] + prefix[i - 1];
        }
        // 1 2 2 2 5 0
        // 1 3 5 7 12 12
        // 1 | 2 |2 2 5 0
        // prefix[i]<= prefix[j]-prefix[i] <= prefix[n-1] - prefix[j]
        long long ans = 0;
        long total = prefix[n - 1];
        for (int i = 0; i < n - 2; i++) {
            long left = prefix[i];
            long right = (total + left) / 2;
            int l = i + 1;
            int r = n - 2;
            int midstart;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (prefix[mid] >= 2 * left)
                    r = mid - 1;
                if (prefix[mid] <2 *  left)
                    l = mid + 1;
            }
            midstart = l;
            int midend;
            l = midstart;
            r = n - 2;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (prefix[mid] > right)
                    r = mid - 1;
                if (prefix[mid] <= right)
                    l = mid + 1;
            }
            midend = r;
            if (midstart <= midend)
                ans = (ans + midend - midstart + 1) % MOD;
        }
        return ans;
    }
};