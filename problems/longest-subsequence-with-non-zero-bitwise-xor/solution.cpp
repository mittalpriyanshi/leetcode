class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // xor is zero if both numbers are equal
        int n=nums.size();
        int x=0;
        vector<int> zeros(n, 0);
        if (nums == zeros) {
            return 0;
        }
        for(int num: nums){
            x = x^num;
        }
        if(x!=0) return n;
        else return n-1;   
    }
};