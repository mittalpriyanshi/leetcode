class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int countEven=0, countOdd=0;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0) countEven++;
            if(nums1[i]%2!=0) countOdd++;
        }
        if(countEven==n || countOdd==n) return true;
        else if(countOdd>1 || countEven>0) return true;
        return false;
    }
};