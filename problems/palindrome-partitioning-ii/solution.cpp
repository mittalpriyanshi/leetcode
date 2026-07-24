class Solution {
public:
    int minCut(string s) {
        return solve(s,0)-1;
    }
    bool isPalind(string& s, int l, int r ){
        while(l<r) {
            if(s[l++]!=s[r--]) return false;
        }
        return true;
    }
    int solve(string s, int i){
        int ans = INT_MAX;
        if(i==s.size()) return 0;
        for(int end =i;end<s.size();end++){
            if (isPalind(s,i,end)){
                ans = min(ans, 1+ solve(s,end+1));
            }
        }
        return ans;

    }
};