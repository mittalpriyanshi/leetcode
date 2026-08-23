class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n=arr.size();
        string s(n,'1');
        if(m==n) return n;
        if(m==n-1){
            if(arr[n-1]!=1 || arr[n-1]!=n) return -1;
            else return n-1;
        } 
        string target(m,'1');
        int l=-1;
        for(int i=n-1;i>=0;i--){
            int curr = arr[i]-1;
            s[curr]='0';
            string left,right;
            if(curr > l){
            left = s.substr(l+1,curr-l-1);
            right = s.substr(curr+1, n-curr+1);
            }
            else{
                left = s.substr(0,curr);
                right = s.substr(curr+1, l-curr-1);
            }
            
            if(left.find(target)!=string::npos && right.find(target)!=string::npos) return i;
            l=arr[i]-1;
        }
        return -1;
    }
};