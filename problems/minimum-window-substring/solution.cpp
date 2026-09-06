class Solution {
public:
    string minWindow(string s, string t) {
        int sn = s.size();
        int tn = t.size();
        if (sn < tn) return "";
        unordered_map<char, int> mpt;
        for (char x : t) mpt[x]++;
        unordered_map<char, int> mps;
        int i = 0, j = 0;
        int totalCharsCovered = 0;
        int minLen = INT_MAX;
        int startIdx = 0; 
        while (j < sn) {
            char c = s[j];
            mps[c]++; 
            if (mpt.count(c) && mps[c] <= mpt[c]) {
                totalCharsCovered++;
            }
            //shrink
            while (totalCharsCovered == tn) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    startIdx = i;
                }
                //Remove the left character to shrink the window
                char leftChar = s[i];
                mps[leftChar]--;
                
                // If removing s[i] breaks our valid window, decrement totalCharsCovered
                if (mpt.count(leftChar) && mps[leftChar] < mpt[leftChar]) {
                    totalCharsCovered--;
                }
                i++; 
            }
            j++; 
        }
        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};