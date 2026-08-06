class Solution {
public:
int productOfDigits(int n){
    int ans=1;
    string s = to_string(n);
    for(char c:s){
        ans *= c-'0';
    }
    return ans;
}
    int smallestNumber(int n, int t) {
        while(!(productOfDigits(n) % t ==0)) n++;
        return n;
    }
};