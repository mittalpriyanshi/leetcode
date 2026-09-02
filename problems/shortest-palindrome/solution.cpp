class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        for(int i=0;i<s.size();i++){
            if(s.substr(0,s.length()-i)== rev.substr(i) ){
                return rev.substr(0,i)+s;
            }
        }
        return rev+s;
    }
};