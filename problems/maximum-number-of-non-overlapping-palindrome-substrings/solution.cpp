class Solution {
public:
bool isPal(string s, int i,int j){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
    int maxPalindromes(string s, int k) {
        int n= s.size();
        int cnt=0, l0=0;
        for(int r=k-1; r<n; r++){
            int l=r-k+1;
            bool add=(l>=l0 && isPal(s,l,r))||(l>l0 && isPal(s,l-1,r));
            if(add)cnt+=1;
            l0+=(-add & r+1-l0);
        }
        return cnt;
    }
};