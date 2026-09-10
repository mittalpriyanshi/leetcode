class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; ++i) {
            projects[i]={capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end());
        priority_queue<int> maxHeap;
        int i = 0;
        for (int j = 0; j < k; ++j) {
            while (i < n && projects[i].first <= w) {
                maxHeap.push(projects[i].second);
                i++;
            }
            //kisi bhi project k liye paisa nai h
            if (maxHeap.empty()) {
                break;
            }
            // Otherwise, take the project with the maximum profit
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};