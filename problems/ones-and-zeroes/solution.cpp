class Solution {
public:
    int findMaxForm(vector<string>& strs,int m,int n) {
        int sz=strs.size();
        vector<vector<int>> freq(2,vector<int>(sz,0));
        // zeroes and ones table
        for(int i=0;i<sz;i++){
            string num=strs[i];
            for(int j=0;j<num.size();j++){
                if(num[j]=='0'){
                    freq[0][i]++;
                }
                else freq[1][i]++;
            }
        }
        //dp, take or not take
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        //dp[i] = numbers of strings taken till i
        for(int i=0;i<sz;i++){
            //count z= freq[0][i];
            //count one = dp[1][i];
            // if z + count_zeroes <=m && one + count_ones <=n
            // can choose to take or not take
            //else not take
            for(int z=m;z>=freq[0][i];z--){
                for(int o=n;o>=freq[1][i];o--){
                    dp[z][o]=max(dp[z][o],1+dp[z-freq[0][i]][o-freq[1][i]]);
                }
            }
        }
        return dp[m][n];
    }
};