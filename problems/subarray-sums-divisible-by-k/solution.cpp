class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int n=nums.size();
        if(n==1) {
            if (nums[0] % k==0) return 1;
            else return 0;
        } 
        vector<int>pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=nums[i]+pre[i-1];
        }
        int ans=0;
        for(int i =0;i<n;i++){
            if(mp.find(pre[i]%k)!=mp.end()){
                ans += mp[pre[i]%k];
                mp[pre[i]%k]++;     
            }
            mp[pre[i]]++;
        }
        return ans;

    }
};