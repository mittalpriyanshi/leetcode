class Solution {
public:
bool valid(long long mid, vector<int>& nums, int k,int n){
    long long sum =0, part=1;
    for(int i=0;i<n;i++){
        if(sum+nums[i]>mid){
            sum=nums[i];
            part++;
            if(part>k) return false;
        }
        else sum += nums[i];
    }
    return true;
}
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        //"minimize the maximum" or "maximize the minimum" of a contiguous sequence means Binary Search on Answer
        //best scenario, k=n and maxEl is the maxelement of arr, so that is the lowest limit
        long long lower = *max_element(nums.begin(), nums.end());
        long long higher = accumulate(nums.begin(), nums.end(),0LL);
        long long res=higher;
        while(lower<=higher){
            long long mid = (lower+higher)/2;
            if(valid(mid,nums,k,n)){
                res =mid;
                higher = mid-1;
            }
            else {
                lower = mid+1;
            }
        }
        return res;

    }
};