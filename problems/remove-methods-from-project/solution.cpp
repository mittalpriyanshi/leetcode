class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        unordered_map<int, vector<int>> isChild;
        for (const auto i : invocations) {
            adj[i[0]].push_back(i[1]);
            isChild[i[1]].push_back(i[0]);
        }
        // infected edges kisi k child nahi hone chaiye
        vector<bool> vis(n, false);
        vis[k] = true;
        queue<int> q;
        q.push(k);
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            for (auto nb : adj[top]) {
                if (!vis[nb]) {
                    q.push(nb);
                    vis[nb] = true;
                }
            }
        }
        bool broken = false;
        for (int i = 0; i < n; i++) {
            if (vis[i] && !isChild[i].empty()) {
                for (auto p : isChild[i]) {
                    if (!vis[p]) {
                        broken = true;
                        break;
                    }
                }
            }
        }
        vector<int> ans;
        if (broken) {
            for (int i = 0; i < n; i++) {
                ans.push_back(i);
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (!vis[i])
                    ans.push_back(i);
            }
        }
        return ans;
    }
};