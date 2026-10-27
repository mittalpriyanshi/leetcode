class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int count=0;
        int idx = n+1;
        for(int i=0;i<n;i++){
            if(nums[i] > k) nums[i] = 1;
            else if(nums[i]< k) nums[i] = -1;
            else if (nums[i]==k) {
                nums[i] = 0;
                idx = i;
            }
        }
        if (idx== n+1) return 0;
        vector<int>pre(n);
        unordered_map<int, vector<int>> mp; //num, indexes
        pre[0] = nums[0];
        mp[pre[0]].push_back(0);
        for(int i=1;i<n;i++){
            pre[i] = nums[i]+pre[i-1];
            if(mp.find(pre[i])!= mp.end()){
                auto vec = mp[pre[i]];
                for(auto x: vec){
                    if(idx>=x && idx<=i) count++;
                }

            }// sum between them is 0;
            if (mp.find(pre[i]-1)!= mp.end()){
                auto vec = mp[pre[i]-1];
                for(auto x: vec){
                    if(idx>=x && idx<=i) count++;
                }
            }// sum between them is 1
            mp[pre[i]].push_back(i);
        }
        return count;
    }
};