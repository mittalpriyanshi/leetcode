class Solution {
public:
    bool checkDivisibility(int n) {
        string s= to_string(n);
        int sum=0, product=1;
        for(auto c: s){
            sum+= c-'0';
            product *= (c-'0');
        }
        int totalsum = sum+product;
        if(n%totalsum==0) return true;
        return false;
    }
};