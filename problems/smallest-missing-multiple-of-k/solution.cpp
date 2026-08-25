class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> set(nums.begin(), nums.end());
        int n=nums.size();
        int x=k;
        for(int i=2;i<=(n+1);i++){
            if(set.count(x)){
                x = k*i;
                continue;
            }
            if(!set.count(x)) return x;
        }
        return x;
    }
};