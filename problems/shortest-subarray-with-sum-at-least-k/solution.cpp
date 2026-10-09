class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1){
            if(nums[0]<k) return -1;
            else return 1;
        }
        vector<int> prefix(n+1);
        prefix[0]=0;
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i]+nums[i];
        }
        deque<int> dq;
        int ans=n+1;
        for(int i=0;i<=n;i++){
            while(!dq.empty() && prefix[i]-prefix[dq.front()]>=k){
                ans = min(ans, i-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && prefix[dq.back()]>= prefix[i]) dq.pop_back();
            dq.push_back(i);
        }
        if(ans==n+1) return -1;
        else return ans;
        
    }
};