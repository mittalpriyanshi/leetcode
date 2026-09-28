class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;
        for (int i = 0; i < n; i++) {
            double ratio = (double)wage[i] / quality[i];
            workers.push_back({ratio, quality[i]});
        }
        sort(workers.begin(), workers.end());
        priority_queue<int> pq;
        double ans=INT_MAX;
        long long qualitySum=0;
        priority_queue<int> maxHeap;
        for(auto [ratio, q]: workers){
            pq.push(q);
            qualitySum += q;
            //only k smalllest
            if(pq.size()>k){
                qualitySum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                ans = min(ans, ratio * qualitySum);
            }
        }
        return ans;
    }
};