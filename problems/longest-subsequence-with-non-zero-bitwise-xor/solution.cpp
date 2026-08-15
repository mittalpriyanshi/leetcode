class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // xor is zero if both numbers are equal
        int n=nums.size();
        int x = nums[0];
        int count=0;
        int maxcount=0;
        for(int i=0;i<n;i++){
            if (x==0){
                count=0;
                if(i+1<n) x=nums[i+1];
                continue;
            }
            count++;
            maxcount = max(count,maxcount);
            if(i+1<n) x=x^nums[i+1];

        }
        return maxcount;
        
    }
};