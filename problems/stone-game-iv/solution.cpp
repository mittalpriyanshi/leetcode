class Solution {
public:
    bool winnerSquareGame(int n) {
        if(n==1) return true;
        if(n==2) return false;
        int x = sqrt(n);
        if(x*x==n) return true;
        vector<bool> dp(n+1,false);
        dp[0] = false;
        dp[1]=true;
        dp[2]=false;
        for(int i=3;i<=n;i++){
           int x = sqrt(i);
           if(x*x == i) dp[i]=true;
           if(!dp[i-(x*x)]) dp[i]=true;
        }
        return dp[n];

    }
};