class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int smol = INT_MAX;
        int secondSmol = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<smol){
                smol = nums[i];
            }
            else if(nums[i]<secondSmol){
                secondSmol = nums[i];
            }
            else return true;
        }
return false;
    }
};