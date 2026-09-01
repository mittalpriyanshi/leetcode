class Solution {
public:
vector<int> dir={0,-1,0,1,0};
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size();
        int n= classroom[0].size();
        int orgEnergy=energy;
        vector<vector<int>>litter(m, vector<int>(n));
        int startRow, startCol;
        int count=0;
        vector<vector<bool>> vis(m, vector<bool>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S') {
                   startRow =i, startCol =j;
                }
                if(classroom[i][j]=='L') {
                   litter[i][j]=count;
                   count++;
                }
                
            }
        }
        int fullmask = (1 << count )-1;
        queue<vector<int>> q;
        q.push({startRow,startCol,0,0,energy}); //i,j,mask,steps,energy
        vis[startRow][startCol]=true;
        while(!q.empty()){
            auto v = q.front();
            int r = v[0], c=v[1], mask= v[2], s=v[3], e=v[4];
                q.pop();
                if(mask==fullmask){
                    return s;
                }
                for(int i=0;i<4;i++){
                    int nr = r+ dir[i];
                    int nc= c+dir[i+1];
                    if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && e>0){
                        if(classroom[nr][nc]=='L'){
                            int pos= litter[nr][nc];
                            mask = mask | 1<<pos;
                            q.push({nr,nc,mask,s+1,e-1});
                        }
                        else if(classroom[nr][nc]=='R'){
                            q.push({nr,nc,mask,s+1,orgEnergy});
                        }
                        else if(classroom[nr][nc]=='.'){
                            q.push({nr,nc,mask,s+1,e});
                        }
                        vis[nr][nc]=true;
                    }         
            }
        }
        return -1;
       
    }
    
};