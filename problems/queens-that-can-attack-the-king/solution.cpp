class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
    vector<pair<int,int>> dir = {
            {0,1},{1,1},{1,0},{1,-1},
            {0,-1},{-1,-1},{-1,0},{-1,1}
        };

        vector<vector<int>> b(8, vector<int>(8,0));
        vector<vector<int>> ans;

        // mark queen positions
        for(auto q : queens){
            b[q[0]][q[1]] = 1;
        }

        // traverse all directions
        for(auto &[dx,dy] : dir){

            int i = king[0] + dx;
            int j = king[1] + dy;

            while(i < 8 && i >= 0 && j < 8 && j >= 0){

                if(b[i][j]){
                    ans.push_back({i,j});
                    break;
                }

                i += dx;
                j += dy;
            }
        }

        return ans;
        
    }
};