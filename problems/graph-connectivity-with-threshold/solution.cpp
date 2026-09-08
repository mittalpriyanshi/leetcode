class DSU{
    public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(),0);
        size.resize(n,1);
    }
    int findPar(int a){
        if(parent[a]==a) return a;
        else return parent[a] = findPar(parent[a]);
    }
    void unite(int a, int b){
        int p1 = findPar(a);
        int p2 =findPar(b);
        if(p1==p2) return;
        if(size[p2]> size[p1]) swap(p1,p2);
        parent[p2]=p1;
        size[p1]+=size[p2];
    }

};
class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DSU graph(10001);
        for(int i=1;i<=n;i++){
            for(int j=1; (j*j)<=i;j++){
                if(i%j==0){
                    if(i/j > threshold){
                        //i/j is common factor greater than thres
                    graph.unite(i, i/j);
                    }
                    if(j > threshold){
                        ///j is common factor greater than thres
                        graph.unite(i, j);
                    }
                }
            }
        }
        vector<bool> res;
        for(auto q: queries){
            int n1 =q[0];
            int n2 =q[1];
            if(graph.findPar(n1) == graph.findPar(n2)) res.push_back(true);
            else res.push_back(false);
        }
        return res;
        
    }
};