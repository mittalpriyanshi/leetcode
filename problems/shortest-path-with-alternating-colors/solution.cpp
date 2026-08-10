class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto e: redEdges){
            int from = e[0];
            int to = e[1];
            adj[from].push_back({to,0}); //0 for red, 1 for blue
        }
         for(auto e: blueEdges){
            int from = e[0];
            int to = e[1];
            adj[from].push_back({to,1}); //0 for red, 1 for blue
        }
        vector<int> ans(n,-1);
        ans[0]=0;
        vector<vector<int>> dist(n, vector<int>(2,INT_MAX));
        dist[0][0]=0; //0 arrived via red
        dist[0][1]=0; //0 arrived via blue
        queue<pair<int,int>> q;
        q.push({0,0});
        q.push({0,1});
        while(!q.empty()){
            auto top = q.front();
            int parent = top.first;
            int prevcolor = top.second;
            q.pop();

            for(auto child: adj[parent]){
                int next = child.first;
                int color = child.second;
                if(child.first == parent){
                    continue; //self edge
                }
                if(color == prevcolor) continue;
                if(dist[next][color]== INT_MAX){ //not reached
                    dist[next][color] = dist[parent][prevcolor] + 1;
                    q.push({next, color});
                } 
            }
        }
        for (int i = 0; i < n; i++) {
            int best = min(dist[i][0], dist[i][1]);
            if (best != INT_MAX)
                ans[i] = best;
        }
        return ans;
    }
};