class DSU{
    public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
   int find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}

void unite(int a,int b){
    a=find(a);
    b=find(b);

    if(a==b) return;

    if(size[a]<size[b]) swap(a,b);

    parent[b]=a;
    size[a]+=size[b];
}
};
 
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n =row.size()/2;
        DSU dsu(n);
        for (int i = 0; i < row.size(); i += 2) {
            int c1 = row[i] / 2;
            int c2 = row[i + 1] / 2;
            dsu.unite(c1, c2);
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i)
                components++;
        }

        return n - components;
    }
};