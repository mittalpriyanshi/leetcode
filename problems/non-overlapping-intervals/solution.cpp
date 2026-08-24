class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[1]<b[1];
        });
        int lastEnd=INT_MIN;
        int count=0;
        for(auto i:intervals){
            int start = i[0];
            int end=i[1];
            if(start<lastEnd) count++;
            else lastEnd = end;
        }
        return count;
    }
};