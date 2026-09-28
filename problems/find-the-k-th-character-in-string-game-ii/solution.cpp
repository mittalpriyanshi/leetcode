class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();
        string s = "a";
        vector<long long> lengthsTill(n);
        long long shift = 0;
        // length of string before ith op;
        lengthsTill[0] = 1;
        for (int i = 1; i < n; i++) {
            lengthsTill[i] = min(k + 1, lengthsTill[i - 1] * 2);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (k > lengthsTill[i]) {
                k -= lengthsTill[i];
                if (operations[i] == 1)
                    shift++;
            }
        }
        shift = shift%26;
        char ans = 'a' + shift;
        return ans;
    }
};