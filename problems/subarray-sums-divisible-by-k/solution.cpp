class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) {
            if (nums[0] % k==0) return 1;
            else return 0;
        } 
        unordered_map<int,int> mp;      
        int prefix=0;
        mp[0]=1;
        int ans=0;
        for(int x: nums){
            prefix +=x;
            int rem = ((prefix %k)+k)%k;
            ans+=mp[rem];
            mp[rem]++;
        }
        return ans;

    }
};