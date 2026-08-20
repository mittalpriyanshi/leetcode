class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n =nums.size();
        int min_sum = nums[0];
        int max_sum= nums[0];
        int runningMax=nums[0], runningMin=nums[0];
        int totalsum=nums[0];
        for(int i=1;i<n;i++){
            totalsum+=nums[i];
            runningMax = max(runningMax+nums[i], nums[i]);
            max_sum = max(runningMax, max_sum);
            runningMin = min(runningMin+nums[i], nums[i]);
            min_sum = min(min_sum, runningMin);
        }        
        int circularSum = totalsum - min_sum;
        if(circularSum==0) return max_sum; //i.e puri array hi negative hai,and minus hokr it results to 0... so the max element is the maxsum;
        //else agar beech ki array h maxsum, toh wo hojayega ans, wrna if turn around krke max hai toh wo hojyega ans
        return max(max_sum, circularSum);
    }
};