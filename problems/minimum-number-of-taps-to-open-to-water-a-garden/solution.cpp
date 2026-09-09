class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> intervals(n+1);
        int lower,higher;
        for(int i=0;i<=n;i++){
            lower = i - ranges[i];
            higher = i+ ranges[i];
            intervals[i].push_back(lower);
            intervals[i].push_back(higher);
        }
        sort(intervals.begin(), intervals.end());
        if(intervals[0][0]>0) return -1;
        int currEnd=0;
        int furthestEnd=0;
        int ans=0;
        int i=0;
        while(i<=n && currEnd<n){
            if (intervals[i][0] > currEnd) {
                return -1;
            }
            while(i<=n && intervals[i][0]<= currEnd){
                furthestEnd = max(furthestEnd, intervals[i][1]);
                i++;
            }
            currEnd= furthestEnd;
            ans++;
        }
        return ans;
    }
};