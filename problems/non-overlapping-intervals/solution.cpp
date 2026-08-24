class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[1]==b[1]) return a[0]>b[0];
            return a[1]<b[1];
        });
        int lastEnd=0;
        int count=0;
        for(auto i:intervals){
            int start = i[0];
            int end=i[1];
            if(start<lastEnd) count++;
            lastEnd = end;
        }
        return count;
    }
};