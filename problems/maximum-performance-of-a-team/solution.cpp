
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed,
                       vector<int>& efficiency, int k) {
        const long long mod = 1e9 + 7;

        vector<pair<int, int>> engineers;

        for (int i = 0; i < n; i++) {
            engineers.push_back({efficiency[i], speed[i]});
        }

        sort(engineers.begin(), engineers.end(),
             [](const auto& a, const auto& b) {
                 return a.first > b.first;
             });

        priority_queue<int, vector<int>, greater<int>> minHeap;

        long long speedTotal = 0;
        long long bestPerformance = 0;

        for (auto& [eff, spd] : engineers) {
            minHeap.push(spd);
            speedTotal += spd;

            if (minHeap.size() > k) {
                speedTotal -= minHeap.top();
                minHeap.pop();
            }

            bestPerformance = max(
                bestPerformance,
                speedTotal * eff
            );
        }

        return bestPerformance % mod;
    }
};
