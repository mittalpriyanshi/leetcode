class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        if(n==2 && nums[0]!=nums[1]) return 2;
        else if(n==2 && nums[0]==nums[1]) return 1;
        int count=1;
        int first = nums[0];
        int i=0;
        while(i<n-1){
        int iprev=i;
        while(i<n-1 && nums[i+1]>=nums[i])
            i++;
        //increasing
        if(nums[i]!=nums[iprev] && i!=iprev) count++;
        iprev=i;
        while(i<n-1 && nums[i+1]<=nums[i]) i++; //decreasing
        if(nums[i]!=nums[iprev] && i!=iprev) count++;
     }
     return count;
    }
};