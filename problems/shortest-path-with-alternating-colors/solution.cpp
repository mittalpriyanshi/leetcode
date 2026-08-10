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
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        queue<vector<int>> q;
        q.push({0,0,-1});
        while(!q.empty()){
            auto top = q.front();
            int parent = top[0];
            int d = top[1];
            int prevcolor = top[2];
            q.pop();
            for(auto child: adj[parent]){
                if(child.first == parent){
                    continue;//self edge
                }
                if(prevcolor==-1){
                    dist[child.first]= min(dist[child.first], d+1);
                    ans[child.first] = dist[child.first];
                    q.push({child.first, d+1,child.second});  
                }
                else if(child.second == prevcolor) continue;
                else {
                    if(dist[child.first]> d+1){
                    dist[child.first]= d+1;
                    ans[child.first] = dist[child.first]; 
                    }
                    q.push({child.first, d+1,child.second});
                }
            }
        }
        return ans;
    }
};