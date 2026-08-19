class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        long long ans = n*2;
        unordered_map<int, unordered_set<int>> mp;
        for(auto r:reservedSeats){
            mp[r[0]].insert(r[1]);
        }
        for(auto &[row, seats]: mp){
            bool left = true;
            bool middle = true;
            bool right = true;

            for(int seat = 2; seat<=5; seat++){
                if(seats.count(seat)){
                    left = false;
                    break;
                }
            }

            for(int seat = 4; seat<=7; seat++){
                if(seats.count(seat)){
                    middle = false;
                    break;
                }
            }

            for(int seat = 6; seat<=9; seat++){
                if(seats.count(seat)){
                    right = false;
                    break;
                }
            }

            if(left && right){

            }
            else if(left || middle || right){
                ans -= 1;
            }
            else{
                ans -= 2;
            }

        }

        return ans;

    }
};