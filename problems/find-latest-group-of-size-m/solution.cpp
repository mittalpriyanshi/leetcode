class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n=arr.size();
     
        if(m==n) return n;
        
        set<int> zeroes;
        zeroes.insert(0); zeroes.insert(n+1);
        for(int i=n-1;i>=0;i--){
            int pos = arr[i];
            auto it = zeroes.upper_bound(pos); //gives us the pointer to the closest zero on the right of the current position
            auto rightBound =*it;
            auto leftBound = *prev(it);  //gives us the pointer to the closest zero on the left of the current position
            int rightLen = rightBound-pos-1;
            int leftLen = pos-leftBound-1;
            if (leftLen == m || rightLen == m) {
                return i;
            }
            zeroes.insert(pos);
        }
        return -1;
    }
};