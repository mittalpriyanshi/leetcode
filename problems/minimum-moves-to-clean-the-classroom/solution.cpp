class Solution {
public:
    vector<int> dir = {0, -1, 0, 1, 0};
    
    int minMoves(vector<string>& classroom, int energy) {
        int rows = classroom.size();       
        int cols = classroom[0].size();   
        int orgEnergy = energy;
        vector<vector<int>> litter(rows, vector<int>(cols,-1));
        int startRow, startCol;
        int count = 0;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(classroom[i][j] == 'S') {
                   startRow = i, startCol = j;
                }
                if(classroom[i][j] == 'L') {
                   litter[i][j] = count;
                   count++;
                }
            }
        }
        if (count == 0) return 0;
        int fullmask = (1 << count) - 1;
        
        // vis[row][col][mask] = max_energy_remaining
        // Initialize with -1 to indicate unvisited
        vector<vector<vector<int>>> vis(rows, vector<vector<int>>(cols, vector<int>(1 << count, -1)));
        
        queue<vector<int>> q;
        q.push({startRow, startCol, 0, 0, energy}); // r, c, mask, steps, energy
        vis[startRow][startCol][0] = energy;
        
        while(!q.empty()){
            auto v = q.front();
            int r = v[0], c = v[1], mask = v[2], s = v[3], e = v[4];
            q.pop();
            
            if(mask == fullmask){
                return s;
            }
            
            if (e == 0) continue; 
            for(int i = 0; i < 4; i++){
                int nr = r + dir[i];
                int nc = c + dir[i+1];
                
                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && classroom[nr][nc] != 'X'){
                    int nextMask = mask;
                    int nextEnergy = e - 1; 
                    
                    if(classroom[nr][nc] == 'L'){
                        int pos = litter[nr][nc];
                        nextMask = mask | (1 << pos); // Use a new variable!
                    }
                    else if(classroom[nr][nc] == 'R'){
                        nextEnergy = orgEnergy; // Reset energy
                    }
                    
                    // Only push if we haven't been here with this mask OR we arrived with strictly more energy
                    if(nextEnergy >= 0 && vis[nr][nc][nextMask] < nextEnergy){
                        vis[nr][nc][nextMask] = nextEnergy;
                        q.push({nr, nc, nextMask, s + 1, nextEnergy});
                    }
                }         
            }
        }
        return -1;
    }
};