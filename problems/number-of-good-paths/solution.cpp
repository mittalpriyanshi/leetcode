class DSU{
    public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end() ,0);
        size.resize(n,1);
    }
    int findUlPar(int a){
        if(parent[a]==a) return a;
        else return parent[a] = findUlPar(parent[a]);
    }
    void unite(int a, int b){
        int p1 = findUlPar(a);
        int p2 = findUlPar(b);
        if(p1==p2) return;
        if(size[p2]> size[p1]) swap(p1,p2);
        parent[p2] = p1;
        size[p1]+=size[p2];
    }

};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<pair<int,int>> nodeVals;
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<n;i++){
            nodeVals.push_back({vals[i],i});
            mp[vals[i]].push_back(i);
        }
        sort(nodeVals.begin(), nodeVals.end());
        vector<vector<int>> adj(n);
        for(auto e:edges){
            int u =e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans =n;
        DSU dsu(n);
        vector<bool> isactive(n, false);
        
        for(auto it: mp){
            int val = it.first;
            vector<int> nodes = it.second;
            for(auto &u:nodes){
                for(int v: adj[u]){
                    if(isactive[v]){
                        dsu.unite(u,v);
                    }
                }
                isactive[u]=true;
            }

            vector<int> ulParents;
            for(int &u: nodes){
                ulParents.push_back(dsu.findUlPar(u));
            }
            int size = ulParents.size();
            sort(ulParents.begin(),ulParents.end());
            for(int i=0;i<size;i++){
                long long count=0;
                int ulP = ulParents[i];
                while(i<size && ulParents[i]==ulP){
                    count++;
                    i++;
                }
                i--;
                ans += (count * (count-1) )/2;
            }
        }
        return ans;
    }
};