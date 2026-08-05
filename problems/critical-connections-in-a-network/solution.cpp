class Solution {
public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        vector<bool> vis(n, false);
        vector<int> startTime(n);
        vector<int> lowestTime(n);
        vector<vector<int>> bridges;
        // source as 0
        startTime[0] = lowestTime[0]=1;
        int runningTime =1;
        logic(0,-1,runningTime,adj,vis,startTime, lowestTime, bridges);
        return bridges;
    }
    void logic(int node, int parent, int& runningTime, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& st, vector<int>& lt, vector<vector<int>>& bridges ) {
        vis[node]=true;
        st[node] = lt[node]=runningTime;
        runningTime++;
        for(const auto child : adj[node]){
            if(child == parent) continue;
            if(!vis[child]){
                logic(child,node, runningTime, adj, vis, st,lt,bridges);
                lt[node] = min(lt[node], lt[child]);
                if(lt[child] > st[node]){
                    bridges.push_back({child,node});
                }
            }
            else lt[node] = min(lt[node], st[child]);
        }

    }
};