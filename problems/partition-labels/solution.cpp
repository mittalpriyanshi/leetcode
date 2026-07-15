class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        unordered_map<char, int> lastApp;
        for (int i = n - 1; i >= 0; i--) {
            if (lastApp.find(s[i]) == lastApp.end())
                lastApp[s[i]] = i;
        }
        vector<int> res;
        int left = 0, right = 0;
        int leftB = 0;
        while (right < n) {
            while (left <= right) {
                right = max(right, lastApp[s[left]]);
                left++;
            }
            res.push_back(right - leftB+1);
            right++;
            leftB = right;
        }
        return res;
    }
};