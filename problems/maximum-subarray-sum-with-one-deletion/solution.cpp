class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n= arr.size();
        if(n==1) return arr[0];
        int no_del=arr[0];
        int global_max=arr[0];
        int del=0;
        for(int i=1;i<n;i++){
            del = max(del+arr[i],no_del); //keep, delete
            no_del = max(no_del+arr[i], arr[i]);
            global_max = max({global_max, del,no_del});
        }
        return global_max;
    }
};