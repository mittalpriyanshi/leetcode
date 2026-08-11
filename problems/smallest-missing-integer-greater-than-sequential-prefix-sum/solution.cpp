class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int i=1;
        int sum=nums[0];
        while(i<n){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
                i++;
            }
            else break;
        }
        vector<bool> hashBool(1276, false);
        for(int num : nums)
            hashBool[num] = true;

        while(hashBool[sum])
            sum++;

        return sum;

    }
};