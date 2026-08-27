class Solution {
public:
 vector<vector<int>> adj;
 vector<int> color;
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        adj.resize(n+1, vector<int>());
        for(auto d:dislikes){
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }
        color.resize(n+1,2);
        bool res=true;
        for(int i=1;i<=n;i++){
            if(color[i]==2) {
                res =(res && bfs(i)) ;
            }
        }
        return res;
          
    }
    bool bfs(int node){
           queue<int> q;
        q.push(node);
        color[node]=0;
        while(!q.empty()){
            int p=q.front();
            q.pop();
            int pc = color[p];
            for(auto child: adj[p]){
                if(color[child]==pc) return false;
                if(color[child]==2) {
                    (pc==1)?color[child] =0:color[child] =1;
                     q.push(child);
                }
               
            }
        }
        return true;
    }
};