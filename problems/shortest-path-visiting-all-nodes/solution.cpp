class Solution {

public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int allVisited = (1 << n) - 1;
        queue<pair<int, int>> q; // node,mask;
        vector<vector<bool>> visitedMasks(n, vector<bool>((1 << n), false));
        // for (int i = 0; i < n; i++) {
        //     if (graph[i].size() < 2) {
        //         int mask = (1 << i);
        //         q.push({i, mask});
        //         visitedMasks[i][mask] = true;
        //     }
        // }
        
            for (int i = 0; i < n; ++i) {
                q.push({i, 1 << i});
                visitedMasks[i][1 << i] = true;
            }
        
        int pathlen = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto f = q.front();
                q.pop();
                int nodeParent = f.first;
                int maskParent = f.second;
                if (maskParent == allVisited)
                    return pathlen; //jo phela mil gya whi shortest
                for (int neigh : graph[nodeParent]) {
                    int newMask = maskParent | (1 << neigh);
                    if (visitedMasks[neigh][newMask])
                        continue;
                    visitedMasks[neigh][newMask] = true;
                    q.push({neigh, newMask});
                }
                
            }
            pathlen++;
        }
        return -1;
    }
};