class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            //if indice in the start are beyond the limits
            while(!dq.empty() && dq.front()<=i-k) dq.pop_front();
            
            //if indice at the back is less than the current element
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);

            //if window size = k
            if(i>=k-1)  ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};