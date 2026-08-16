class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(), false);
        return dfs(arr, start, vis);
    }
    bool dfs(vector<int>& arr, int start,vector<bool>& vis ){
        if(start >= arr.size()) return false;
        if(arr[start]==0) return true;
        vis[start]=true;
        bool ans = false;
        int fv=start+arr[start],bv=start-arr[start];
        if(fv<arr.size() && !vis[fv])
        ans|=dfs(arr,fv,vis);
        if(bv>=0 && !vis[bv])
        ans|=dfs(arr,bv,vis);
        return ans;
    }
};