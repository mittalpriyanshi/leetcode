class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1)
            return 1;
        int maxlen=0;
        int l=0,r=1;
        while(r<arr.size()){
            if(arr[r-1]==arr[r]) l=r;
            else if(r==1 ||
            arr[r-2]> arr[r-1] and arr[r-1]< arr[r]||
            arr[r-2]< arr[r-1] and arr[r-1]> arr[r]){}
            else l=r-1;
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};