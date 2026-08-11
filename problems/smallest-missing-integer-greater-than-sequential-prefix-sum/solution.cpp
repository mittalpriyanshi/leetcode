class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int maxE = *max_element(nums.begin(), nums.end());
        int maxSum=0;
        int i=1;
        int sum=nums[0];
        while(i<n){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
            }
            else{
                maxSum = max(maxSum, sum);
                sum=nums[i];
            }
            i++;
        }
        maxSum = max(maxSum, sum);
        if(maxE >= maxSum) return maxE+1;
        else return maxSum;
    }
};