class DSU{
    public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
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
        if(size[b] > size[a]) swap(a,b);
        parent[p2] = p1;
        size[p1]+=size[p2]; 
    }
    int findSize(int x) {
        return size[findUlPar(x)];
    }
};


class Solution {
public:
vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size();
        int n= grid[0].size();
        // DSU is always good at joining, not breaking.
        //so reverse dsu
        //first mark the hits on the grid
        for(auto h: hits){
            grid[h[0]][h[1]]--;
        }
        DSU dsu(m*n + 1);
         // One extra node = virtual TOP
        int TOP = m * n;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(i==0) dsu.unite(TOP, i*m + j);
                }
            if(i>0 && grid[i-1][j]==1){
                dsu.unite(i*m + j, (i-1)*m+j);
            }
            if(j>0 && grid[i][j-1]==1){
                dsu.unite(i*m + j, (i)*m+(j-1));
            }

            }
        }
        //initial connections bna liye, ab reverse hits dekhenge and connect krenge
        // the difference between the initial and final size of TOP will tell us how many bricks would have fallen
        int k=hits.size();
        vector<int> res(k);
        for(int h=k-1;h>=0;h--){
            int hr = hits[h][0];
            int hc = hits[h][1];

            grid[hr][hc]++;
            if(grid[hr][hc]!=1){
                continue; // no brick was there 
            }
            int prevComponentSize = dsu.findSize(TOP);
            //neighbours se unite
            for(int i=0;i<4;i++){
                int nr = hr + dr[i];
                int nc = hc+ dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1) dsu.unite(hr*m + hc, nr*m + nc);
            }
            if(hr==0) dsu.unite(TOP, hr*m + hc);
            int newSize = dsu.findSize(TOP);

            // agar dono connected hain toh dono ka size same hoga
            if(dsu.findSize(TOP)== dsu.findSize(hr*m+hc)){
                res[h]=max(0, newSize - prevComponentSize-1);
            }
        }
        return res;
    }
};