class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n= nums.size();
        //minimise the max so binary search on answer
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int mid;
        int ans;
        while(low<=high){
            mid =  low + (high-low)/2 ;
            if(canRob(nums,k, mid)){
                ans=mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    bool canRob(vector<int>& nums, int k, int capa){
        int robbed=0;
        int i=0;
        while(i<nums.size() && robbed <k){
            if(nums[i]<=capa){
                robbed++;
                i+=2; //can rob
            }
            else i++;
        }
        return robbed >= k;
    }
};