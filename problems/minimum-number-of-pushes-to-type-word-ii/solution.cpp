class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        unordered_map<char, int> mp;
        for (auto c : word) {
            mp[c]++;
        }
        if (mp.size() < 9)
            return word.size();
        vector<long long> freq;
        for (auto [k, v] : mp) {
            freq.push_back(v);
        }
        sort(freq.begin(), freq.end(), greater<int>());
        long long ans = 0;
        int i = 0;
        while (i < freq.size()) {
            if (i < 8)
                ans += freq[i];
            else if (i >= 8 && i < 16)
                ans = ans + (freq[i] * 2);
            else if (i >= 16 && i < 24)
                ans = ans + (freq[i] * 3);
            else
                ans = ans + (freq[i] * 4);
            i++;
        }
        return ans;
    }
    };