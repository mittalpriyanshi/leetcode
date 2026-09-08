class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }
    int findPar(int a) {
        if (parent[a] == a)
            return a;
        else
            return parent[a] = findPar(parent[a]);
    }
  void unite(int a, int b) {
        int p1 = findPar(a);
        int p2 = findPar(b);
        if (p1 == p2)
            return;
        if (size[p2] > size[p1])
            swap(p1, p2);
        parent[p2] = p1;
        size[p1] += size[p2];
        
    }
};
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int e= edgeList.size();
        int q=queries.size();
        DSU ds(n);
        // to store original indices before shuffling
        for (int i = 0; i < q; i++)
            queries[i].push_back(i);

        // sorting via weight or limit
        sort(queries.begin(), queries.end(),
             [](auto& l, auto& r) { return l[2] < r[2]; });
        sort(edgeList.begin(), edgeList.end(),
             [](auto& l, auto& r) { return l.back() < r.back(); });
        
        vector<bool> res(q,false);
        int i=0;
        for(auto q: queries){
            // using 2 pointers, join edges till weight is less than current query, and since we sorted the queries in asencding order of limit, we'll always have a graph which is relevant in the future as well
            while(i<e && edgeList[i][2]<q[2]){
                ds.unite(edgeList[i][0], edgeList[i][1]);
                i++;
            }
            if(ds.findPar(q[0])== ds.findPar(q[1])) res[q[3]] = true;
        }
        return res;
    }
};