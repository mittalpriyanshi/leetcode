class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int,int> mp; // rem, last index
        int prefix=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            prefix += nums[i];
            int rem = prefix%k;
            if(mp.find(rem)!= mp.end() && i-mp[rem]>=2) return true;
            mp[rem]=min(i, mp[rem]);
        }
        return false;
    }
};