class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int a:nums) mp[a]++;
        int ansOdd=0, ansEven=0;
        for(auto [v,k]:mp){
            if(v%2==0) ansEven+=(k*v);
            else ansOdd+=(k*v);
        }
        return max(ansEven, ansOdd);
    }
};