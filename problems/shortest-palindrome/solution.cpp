class Solution {
public:
    string shortestPalindrome(string s) {
    int n = s.length();
       string rev = s;
       reverse(rev.begin(), rev.end());
       string temp = s +"#"+rev;
       vector<int> LPS(temp.length(),0);
       fillLps(LPS, temp);
       int lpslen = LPS[temp.length()-1];
       string res = rev.substr(0, n-lpslen)+s ;
       return res;
    }
    void fillLps(vector<int>& lps, string temp){
        int t = temp.size();
        int j=0;
        for(int i=1;i<t;i++){
            while(j>0 && temp[i]!= temp[j]){
                j=lps[j-1];
            }
            if(temp[i]==temp[j]) j++;
            lps[i]=j;
        }
    }
};