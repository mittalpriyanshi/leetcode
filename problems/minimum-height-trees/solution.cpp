class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        if(n==0) return {};
        vector<vector<int>> adj(n);
        vector<int>degrees(n,0);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degrees[e[0]]++;
            degrees[e[1]]++;
        }
        vector<int> res;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degrees[i]==1) q.push(i);
        }
        while(!q.empty()){
            res.clear();
            int s = q.size();
            for(int i=0;i<s;i++){
                int curr = q.front();
                q.pop();
                res.push_back(curr);
                for(auto neigh : adj[curr]){
                    degrees[neigh]--;
                    if(degrees[neigh]==1) q.push(neigh);
                }
            }
        }
       return res;
     
    }
};