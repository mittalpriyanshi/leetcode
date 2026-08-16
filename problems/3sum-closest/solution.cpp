class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n= nums.size();
        if(n==3) return nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        unordered_map<int,int> diff; //diff,sum
        int right = n-1;
        for(int i=0;i<n-2;i++){
            int sum = nums[i];
            int left=i+1;
            while(left<right){
                sum = sum +nums[left] +nums[right];
                if(sum==target) return sum;
                diff[abs(sum-target)] = sum;
                left++;
            }
        }
        int minK=INT_MAX;
        for(auto [k,v]: diff){
            minK = min(minK,k);
        }
        return diff[minK];

    }
};