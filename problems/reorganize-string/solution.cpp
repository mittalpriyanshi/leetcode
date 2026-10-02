class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        vector<char> sorted;
        for (auto& [k, v] : freq) {
            if (v != 0)
                sorted.push_back(k);
        }
        sort(sorted.begin(), sorted.end(),
             [&](char a, char b) { return freq[a] > freq[b]; });

        if (freq[sorted[0]] > (n + 1) / 2) {
            return "";
        }
        string res(n,' ');
        int i=0;
        for(char c: sorted){
            for(int j=0;j< freq[c];j++){
                if(i>=n) i=1;
                res[i]=c;
                i+=2;
            }
        }
        return res;
    }
};