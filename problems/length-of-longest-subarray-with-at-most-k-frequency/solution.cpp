class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int i = 0, j = 0;
        int maxlen = 0;
        while (j < n && i <= j) {
            while (i <= j && freq[nums[j]] >= k) {
                freq[nums[i]]--;
                i++;
            }
            freq[nums[j]]++;
            maxlen = max(maxlen, j - i + 1);
            j++;
        }
        return maxlen;
    }
};