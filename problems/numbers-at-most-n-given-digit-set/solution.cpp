
class Solution {
public:
    string s;
    int dp[20][2];

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        s = to_string(n);
        int sz = s.size();
        int dsize = digits.size();

        memset(dp, -1, sizeof(dp));

        long long total = 0;

        // Count numbers with fewer digits
        for (int len = 1; len < sz; len++) {
            total += pow(dsize, len);
        }

        total += solve(0, 1, digits, s);
        return total;
    }

    int solve(int pos, int tight,
              vector<string>& digits, string& up) {
        if (pos == up.size())
            return 1;

        if (dp[pos][tight] != -1)
            return dp[pos][tight];

        int ans = 0;

        for (auto& p : digits) {
            char d = p[0];

            if (tight && d > up[pos])
                continue;

            ans += solve(
                pos + 1,
                tight && (d == up[pos]),
                digits,
                up
            );
        }

        return dp[pos][tight] = ans;
    }
};
