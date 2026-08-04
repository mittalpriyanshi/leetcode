class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<bool> vis(n+1, false);
        vector<vector<int>> adj(n+1);
        vector<int> outDegree(n+1,0);
        unordered_map<int, vector<int>> times;
        times[0].push_back(1);
        vector<vector<int>> children(n+1);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            outDegree[e[0]]++;
            outDegree[e[1]]++;
        }
        queue<int> q;
        q.push(1);
        int tCount=0;
        while(!q.empty()){
            int size = q.size();
            tCount++;
            while(size--){
            int p = q.front();
            vis[p]=true;
            q.pop();
            for(auto child : adj[p]){
                if(outDegree[child]==0 || vis[child]==true) continue;
                outDegree[child]--;
                children[p].push_back(child);
                times[tCount].push_back(child);
                q.push(child);
            }
            }
        }
        double ans=1;
        if(t<=tCount && find(times[t].begin(), times[t].end(), target)== times[t].end()) return 0;
        else{
            int tStart=1;
            while(tStart<=t && tStart<=tCount){
                ans = ans * (double(1)/double(times[tStart].size()));
                // if(find(times[tStart].begin(), times[tStart].end(), target) != times[tStart].end()) return ans;
                tStart++;
            }
        }
        return ans;
    }
};