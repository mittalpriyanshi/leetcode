class dsu{
    public:
    vector<int> parent;
    vector<int> size;
    dsu(int n){
        parent.resize(n);
        size.resize(n,1);
        iota(parent.begin(), parent.end(),0);
    }
    int findPar(int x){
        if (parent[x]==x) return x;
        return parent[x]=findPar(parent[x]);
    }
    void unite(int a,int b){
        int parent1 = findPar(a);
        int parent2 = findPar(b);
        if(parent1==parent2) return;
        if(size[parent1]< size[parent2]) swap(parent1,parent2);
        parent[parent2]=parent1;
        size[parent1]+=size[parent2];
    }
};

class Solution {
public:

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size(); //indices ko union krenge so what elements are present, they dont matter
        dsu con(n);
        for(auto &swap:allowedSwaps){
            con.unite(swap[0], swap[1]);
        }
        unordered_map<int, multiset<int>> mp; //parent indice, {konsa element h udhr, its frequency}
        //mp ko populate krna h
        for(int i=0;i<n;i++){
            mp[con.findPar(i)].insert(source[i]);
        }
        int dist=0;
        for(int i=0;i<n;i++){
            int root = con.findPar(i);
            if(mp[root].count(target[i])) mp[root].erase(mp[root].find(target[i]));
            else dist++;
        }
        return dist;
    }
};