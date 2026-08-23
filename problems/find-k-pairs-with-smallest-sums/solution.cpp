class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n= nums1.size();
        int m = nums2.size();
        vector<vector<int>> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int x:nums2){
            pq.push({nums1[0]+x,0}); //sum, index of nums1 (0)
        }
        while(k-- && !pq.empty()){
            int sum = pq.top().first;
            int idx = pq.top().second;
            ans.push_back({nums1[idx],sum-nums1[idx]});
            pq.pop();
            if(idx<nums1.size()-1){
                pq.push({sum-nums1[idx]+nums1[idx+1], idx+1});
            }
        }
        return ans;
    }
};