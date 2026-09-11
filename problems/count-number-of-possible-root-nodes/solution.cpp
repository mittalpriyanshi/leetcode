class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses,
                  int k) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        // child parent map k liye dfs
        vector<int> parentMap(n);
        set<pair<int, int>> guessSet;

        for (auto& g : guesses) {
            guessSet.insert({g[0], g[1]});
        }
        // let 0 be the root initially
        parentMap[0] = -1;
        dfs1(adj, 0, -1, parentMap);

        int count = 0;
        for (auto g : guesses) {
            int u = g[0];
            int v = g[1];
            if (parentMap[v] == u)
                count++;
        }
        int ans = 0;

        // now during rerooting from parent u to child v, earlier parent[v]=u
        // now parent[u]=v and parent[v]=-1
        dfs2(adj, 0, -1, count, k, ans, guessSet);
        return ans;
    }
    void dfs1(vector<vector<int>>& adj, int root, int parent,
              vector<int>& parentMap) {
        parentMap[root] = parent;
        for (int child : adj[root]) {
            if (child == parent)
                continue;
            dfs1(adj, child, root, parentMap);
        }
    }
    void dfs2(vector<vector<int>>& adj, int u, int parent, int count, int k,
              int& ans, set<pair<int, int>>& guessSet) {

        if (count >= k)
            ans++;

        for (int v : adj[u]) {
            if (v == parent)
                continue;
            int newCount = count;
            if (guessSet.count({u, v}))
                newCount--;
            if (guessSet.count({v, u}))
                newCount++;
            dfs2(adj, v, u, newCount, k, ans, guessSet);
        }
    }
};