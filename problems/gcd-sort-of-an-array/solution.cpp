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
    bool gcdSort(vector<int>& nums) {
        int n=nums.size();
        DSU dsu(100001);
        for(int num: nums){
            for(int i=1;(i*i)<=num;i++){
                if(num%i==0){
                    if(i!=1) dsu.unite(num,i);
                    dsu.unite(num,num/i);
                }
            }
        }
        vector<int> res = nums;
        sort(res.begin(), res.end());
        for(int i=0;i<n;i++){
            if(dsu.findPar(res[i])!= dsu.findPar(nums[i])) return false;
        }
        return true;
    }
};