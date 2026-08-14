class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> freq;
        int i=0,j=0;
        int n = s.size();
        int maxlen=0;
        while(i<=j && j<n){
            while(freq[s[j]]>=2){
                freq[s[i]]--;
                i++;
            }
                freq[s[j]]++;
                maxlen = max(maxlen, j-i+1);
                j++;
        }
        return maxlen;
    }
};