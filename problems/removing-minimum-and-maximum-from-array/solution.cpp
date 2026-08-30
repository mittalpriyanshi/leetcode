class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int count=0;
        int imax, imin;
        int mini=INT_MAX;
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mini){
                mini = nums[i];
                imin=i;
            }
            if( nums[i]>maxi){
                maxi = nums[i];
                imax = i;
            }
        }
        if(imin>imax) swap(imin,imax);
        count = min({imin+1 +n-imax, imax+1,n-imin});
        return count;
    }
};