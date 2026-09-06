class Solution {
public:
int n;
long long maxScore =0;
long long maxCount=0;
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            int parent = parents[i];
            int child = i;
            adj[parent].push_back(child);
        }
        dfs(0, adj);
        return maxCount;
    }
    int dfs(int parent, vector<vector<int>>& adj) {
        int currentSubtreeSize = 1; // current node
        long long currentScore = 1;
        for (auto child : adj[parent]) {
            int nodesChild = dfs(child, adj);
            currentSubtreeSize += nodesChild;
            currentScore *= nodesChild;
        }
        int parentSize = n-currentSubtreeSize;
        if(parentSize>0) currentScore *= parentSize;
        if(currentScore >maxScore){
            maxScore = currentScore;
            maxCount=1;
        }
        else if(currentScore == maxScore) maxCount++;
        return currentSubtreeSize;
    }
};