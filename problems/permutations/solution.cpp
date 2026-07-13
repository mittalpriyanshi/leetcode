class Solution {
public:
vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        recurse(nums,0);
        return res;
    }
    void recurse(vector<int>& nums, int idx){
       if(idx == nums.size()){
        res.push_back(nums);
        return;
       }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            recurse(nums, idx+1);
            swap(nums[i], nums[idx]); //to restore the state
        }
    }
};