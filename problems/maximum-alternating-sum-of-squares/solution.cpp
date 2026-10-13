class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i] = nums[i]*nums[i];
        }
        //max elements ko even places pr, min ko odd places pr
        long long sumPos =0;
        long long sumNeg=0;
        if(n%2==0){
            sort(nums.begin(), nums.end());
            for(int i=0;i<n/2;i++){
                sumNeg += nums[i];
            }
            for(int i=n/2;i<n;i++){
                sumPos += nums[i];
            }
            return sumPos - sumNeg;
        }
        else{
            sort(nums.begin(), nums.end(), greater<int>());
            for(int i=0;i<=n/2;i++){
                sumPos += nums[i];
            }
            for(int i=n/2 +1 ;i<n;i++){
                sumNeg += nums[i];
            }
            return sumPos - sumNeg;
        }
    }
};