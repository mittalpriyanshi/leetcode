class Solution {
public:
    int findIntegers(int n) {
        int dp[32]; //bit positions.. 1st bit position = dp[1] with 2^0
        dp[0]=1; //none of the bit is set = 0
        dp[1] = 2; //1
        dp[2]=3; //2
        for (int i=3;i<=31;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        int ans = 0;
        int prev =0;
        for(int i=30;i>=0;i--){
            if(n & (1<< i)){
                ans += dp[i];
            if (prev==1) return ans;
            prev=1;
            }
            else prev=0;  
        }
        return ans+1;
    }
};