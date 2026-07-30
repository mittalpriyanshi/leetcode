class Solution {
public:

    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<vector<int>> adj(n);
vector<int> degree(n);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        //repeatedly prune leaves which have zero coins
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==1 && coins[i]==0) q.push(i);
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(degree[u]==0) continue;
            degree[u]=0;
            for(auto neigh : adj[u]){
                if(degree[neigh]>0){
                    degree[neigh]--;
                    if(degree[neigh]==1 && coins[neigh]==0) q.push(neigh);
                }
            }
        }
        //now we prune 2 nodes from the leaves up(automatically, saari leaves k paas 1 coin hai at this stage)
        //kyunki unpr toh hum pohonch hi skte hain
        for(int level=1;level<=2;level++){
        for(int i=0;i<n;i++){
            if(degree[i]==1) q.push(i); //first leaf node
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(degree[u]==0) continue;
            degree[u]=0;
            for(auto neigh : adj[u]){
                if(degree[neigh]>0){
                    degree[neigh]--;
                }
            }
        }
        }
        //remaining edges krne hi pdenge traverse
        int cnt=0;
        for(auto e:edges){
            if(degree[e[0]] >0 && degree[e[1]] >0) cnt++;
        }
        return cnt*2;
    }
};