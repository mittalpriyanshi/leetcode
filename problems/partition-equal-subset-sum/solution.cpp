class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int x:nums) total+=x;
        if(total%2!=0) return false;
        vector<bool> dp(n,false);
        //dp[i] tak ka sum ka aadha bna skte ho ki nhi
        return solve(total/2,0,nums);
    }
    bool solve(int target, int i, vector<int>& nums){
        if(i==nums.size() && target!=0) return false; 
        if(target==0) return true;
        if(nums[i]<=target){
            //if pick
            bool pick = solve(target-nums[i],i+1,nums);
        //if not pick
         bool notpick = solve(target,i+1,nums);
         return (pick || notpick);
        }
        else {
            return solve(target,i+1,nums);
        }
       
    }
};