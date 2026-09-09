class Solution {
public:
    long long countCommas(long long n) {
        string s = to_string(n);
        int size = s.size();
        if(n<1000) return 0;
        vector<int> commas = {0,0,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7};
        vector<int> nums(size);
        long long count=4;
        long long ans=0;
        while(count<size){
            ans= ans+ 9*(pow(10,count-1))* commas[count];
            count++;
        }
        ans += (n - pow(10,size-1) +1)* commas[size];
        return ans;
    }
};