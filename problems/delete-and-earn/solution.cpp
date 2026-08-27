class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> points;
        for(int a:nums) points[a]+=a;
        set<int>st(nums.begin(), nums.end());
        int take = 0; 
        int skip = 0; 
        int prevNum = -1;
        for(int num: st){
            int currPoints = points[num];
            if(num==prevNum+1){
                // either skip this and take the max value of take/skip from before to define our new skip state
                int newSkip = max(take, skip);
               // or take this and skip the prev
               int newTake = currPoints + skip;
               take = newTake;
                skip = newSkip;
            }
            else{
                //le hi lo fir
                int newTake = max(take, skip) + currPoints;
                int newSkip = max(take, skip);
                
                take = newTake;
                skip = newSkip;
            }
            prevNum = num;
        }
        return max(skip,take);
    }
};