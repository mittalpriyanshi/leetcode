class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool>dp(n+1, false);
        dp[0]=true;
        for(int i=0;i<n;i++){
            if(!dp[i]) continue;
            for(auto word: wordDict){
                int size = word.size();
                if(i+size <=n && s.substr(i,size)==word) dp[i+size] = true;
            }
        }
        return dp[n];
    }
};