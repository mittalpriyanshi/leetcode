class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
         vector<int> indegree(n,0);
        //  vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){     
            //adj[i].push_back(favorite[i]);
            indegree[favorite[i]]++;
        }
        //max of length of longest cycle > 2
        // vs length of acylic chains with mutual favourites, i.e
        // chain upto A + A<->B (mutuals) + cycle upto B -> and esa saare mutuals k saath we can do
        vector<int> chainLen(n);
        vector<bool> vis(n, false);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node]=true;
            int next = favorite[node];
            chainLen[next] = chainLen[node]+1; 
            // storing chain lens to calculate this part --> chain upto A + A<->B (mutuals) + cycle upto B
            indegree[next]--;
            if(indegree[next]==0) q.push(next);
        }
        int maxCycle = 0, totalChains = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                int current = i, cycleLength = 0;
                while (!vis[current]) {
                    vis[current] = true;
                    current = favorite[current];
                    cycleLength++;
                }

                if (cycleLength == 2) {
                    totalChains += 2 + chainLen[i] + chainLen[favorite[i]];
                } else {
                    maxCycle = max(maxCycle, cycleLength);
                }
            }
        }

        return max(maxCycle, totalChains);
    }
};