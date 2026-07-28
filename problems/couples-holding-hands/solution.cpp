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
    void doUnion(int a, int b){
        parent[b]=parent[a];
        size[a]++;
    }
};
 
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n =row.size();
        DSU con(n);
        int misplaced=0;
        unordered_map<int,int> locs;
        for(int i=0;i<n;i++){
            locs[row[i]]=i;
        }
        for(int i=0;i<n-1;i+=2){
            con.doUnion(locs[i], locs[i+1]);
        }
        for(int i=1;i<n;i+=2){
            if(con.parent[i]!=con.parent[i-1]) misplaced++;
        }
        if (misplaced==0) return 0;
        return misplaced-1;
    }
};