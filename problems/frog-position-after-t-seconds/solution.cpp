class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if (n == 1) return 1.0;

        vector<vector<int>> adj(n + 1);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n + 1, false);
        // Queue stores pair of {node, current_probability}
        queue<pair<int, double>> q;
        
        q.push({1, 1.0});
        vis[1] = true;

        int time = 0;

        while (!q.empty() && time <= t) {
            int sz = q.size();
            
            while (sz--) {
                auto [node, prob] = q.front();
                q.pop();

                // Count unvisited neighbors (children)
                int children = 0;
                for (int neighbor : adj[node]) {
                    if (!vis[neighbor]) children++;
                }

                // If this is our target node
                if (node == target) {
                    // It's correct if we reached target at exact time t,
                    // OR we reached it earlier and it's a leaf node (children == 0)
                    if (time == t || (time < t && children == 0)) {
                        return prob;
                    }
                    return 0.0;
                }

                // Spread probability to unvisited children
                for (int neighbor : adj[node]) {
                    if (!vis[neighbor]) {
                        vis[neighbor] = true;
                        q.push({neighbor, prob / children});
                    }
                }
            }
            time++;
        }

        return 0.0;
    }
};