class Solution {
public:
 const long long MOD = 1e9 + 7;
    int maxProfit(vector<int>& inventory, int orders) {
       
        sort(inventory.begin(), inventory.end(), greater<int>());
        inventory.push_back(0);
        long long ans = 0;

        for (int i = 0; i < inventory.size() - 1; i++) {
            long long high = inventory[i];
            long long low = inventory[i + 1];

            // Number of colors having at least 'high' balls
            long long cnt = i + 1;
            long long balls = cnt * (high - low);

            if (orders >= balls) {
                // For every color:
                // high + (high-1) + ... + (low+1)
                long long sum =
                    (high + low + 1) * (high - low) / 2;

                ans = (ans + cnt * sum) % MOD;

                orders -= balls;
            }
            else {

                // We cannot finish the whole level.

                long long full = orders / cnt;
                long long rem = orders % cnt;

                // Sell 'full' levels from every color
                //
                // Example:
                // high = 5, full = 2
                // sell: 5 + 4
                //
                // low after these sales = 3
                long long newLow = high - full;
                long long sum =
                    (high + newLow + 1) * full / 2;
                ans = (ans + cnt * sum) % MOD;
                // Remaining balls are sold at newLow
                ans = (ans + rem * newLow) % MOD;

                break;
            }
        }

        return ans;
    }
};