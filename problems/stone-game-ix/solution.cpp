class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size();
        int allsum=0;
        for(auto x:stones) allsum+=x;
        if(n%2!=0) return false;
        else if(allsum%3!=0) return false;
        return true;
    }
};