class Solution {
public:
const long long MOD = 1e9+7;
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<int> lastPos(26,-1);
        vector<long long> dp(n);
        dp[0]=1;
        lastPos[s[0]-'a']=0;
        for(int i=1;i<n;i++){
            int c = s[i]-'a';
            if(lastPos[c]!=-1){
                if(lastPos[c]==0) dp[i]= 2*dp[i-1] % MOD ;
                else dp[i]=(2*dp[i-1]%MOD - dp[lastPos[c]-1]+MOD)%MOD;
                lastPos[c]=i;
            }
            else{
                dp[i]= (dp[i-1]*2)%MOD+1;
                lastPos[c]=i;
            }
        }
        return dp[n-1]%MOD;
    }
};