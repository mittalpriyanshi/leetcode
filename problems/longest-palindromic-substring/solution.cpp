class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        string ans = "";
        ans+=s[0];
        for(int i=0;i<n;i++) 
        for(int start=0;start<n;start++){
            dp[start][start]=true;
            for(int end=start;end<n;end++){
                if(s[start]==s[end] && (end-start<=2 || dp[start+1][end-1]==true)){
                    dp[start][end]=true;
                    string subs = s.substr(start, end-start+1);
                    if(subs.size()>ans.size()) ans = subs;
                }
            }
        }
        return ans;
    }
};