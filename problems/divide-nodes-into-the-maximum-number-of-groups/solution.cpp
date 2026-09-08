class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }
    int findPar(int a) {
        if (parent[a] == a)
            return a;
        else
            return parent[a] = findPar(parent[a]);
    }
    void unite(int a, int b) {
        int p1 = findPar(a);
        int p2 = findPar(b);
        if (p1 == p2)
            return;
        if (size[p2] > size[p1])
            swap(p1, p2);
        parent[p2] = p1;
        size[p1] += size[p2];
    }
};

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        DSU dsu(n + 1);
        vector<vector<int>> adj(n + 1);
        vector<int> maxDepthInComp(n + 1, 0);
        for (auto e : edges) {
            dsu.unite(e[0], e[1]);
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for (int i = 1; i <= n; i++) {
            vector<int> dist(n + 1, -1);
            queue<int> q;
            q.push(i);
            dist[i] = 1;
            int maxDepth = 1;
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int neighbor : adj[curr]) {
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[curr] + 1;
                        maxDepth = max(maxDepth, dist[neighbor]);
                        q.push(neighbor);
                    } else if (dist[neighbor] == dist[curr]) {
                        return -1;
                    }
                }
            }
            // to find maxDepth of the parent of the component
            int root = dsu.findPar(i);
            maxDepthInComp[root] = max(maxDepthInComp[root], maxDepth);
        }
        int total = 0;
        for (int i = 1; i <= n; i++) {
            if (dsu.findPar(i) == i) { // Only add values starting at root nodes
                total += maxDepthInComp[i];
            }
        }

        return total;
    }
};