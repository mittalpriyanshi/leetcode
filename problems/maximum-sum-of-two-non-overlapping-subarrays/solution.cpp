class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        int sum1=0, sum2=0;
        vector<int> sumF(n,-1);
        vector<int> sumS(n,-1);
        int l=0, r1=firstLen-1, r2=secondLen-1;
        for(int i=0;i<=r1;i++){
            sum1+= nums[i];
        }
        for(int i=0;i<=r2;i++){
            sum2+= nums[i];
        }
        sumF[0]=sum1;
        sumS[0]=sum2;
        while(r1+1<n){
            sum1 -= nums[l];
            l++;
            r1++;
            sum1+=nums[r1];
            sumF[l]= sum1;
        }
        
        l=0;
        while(r2+1<n){
            sum2 -= nums[l];
            l++;
            r2++;
            sum2 +=nums[r2];
            sumS[l] = sum2;
        }
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        for(int i=0;i+firstLen<n;i++){
            for(int j=i+firstLen;j<n ;j++){
                if(sumS[j]==-1) break;
                max1 = max(max1, sumF[i]+ sumS[j]);
            }
        }
         for(int i=0;i+secondLen<n;i++){
            for(int j=i+secondLen;j<n ;j++){
                if(sumF[j]==-1) break;
                max2 = max(max2, sumS[i]+ sumF[j]);
            }
        }
        return max(max1, max2);

    }
};