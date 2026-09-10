class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; 
        //min heap // current num, listindex, numberoflistindex
        int currMax = INT_MIN;
        for(int i=0;i<n;i++){
            pq.push({nums[i][0],i,0});
            currMax = max(currMax, nums[i][0]);
        }
        
        vector<int> bestRange = {0, INT_MAX}; //worst range
        while(!pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();
            int currNum = curr[0];
            int row = curr[1];
            int col = curr[2];
            if(currMax - currNum < bestRange[1]-bestRange[0]){
                bestRange = {currNum, currMax};
            }
            if((col+1) < nums[row].size()){
                pq.push({nums[row][col+1], row, col+1});
                currMax = max(currMax,nums[row][col+1]);
            }
            else break;
        }
        return bestRange;
    }
};