class Solution {
public:
    int countCommas(int n) {
        string s = to_string(n);
        int size = s.size();
        if(n<1000) return 0;
        else{
            if(size==4 || size==5){
                return (n-999);
            }
            if(size==6){
                return (n-999) + (n-99999);
            }
        }
        return 0;
    }
       
};