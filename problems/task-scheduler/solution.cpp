class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        unordered_map<char, int> minTime;
        for (auto c : tasks) {
            freq[c]++;
            minTime[c] = INT_MIN;
        }
        int time = 1;
        priority_queue<pair<int, char>> pq;

        while (!freq.empty()) {
    
            while (!pq.empty())
                pq.pop();
            for (auto [k, v] : freq)
                pq.push({v, k});  

            bool executed = false;
            while (!pq.empty()) {

                auto t = pq.top();
                pq.pop();
                int f = t.first;
                char task = t.second;
                if (minTime[task] <= time) {
                    time++;
                    minTime[task] = time + n;
                    freq[task]--;
                    if (freq[task] == 0)
                        freq.erase(task);
                    executed = true;
                    break;
                }
            }
            // No task was available => idle
            if (!executed) {
                time++;
            }
        }

        return time - 1;
    }
};