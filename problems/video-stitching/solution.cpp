class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        if (clips[0][0] != 0)
            return -1;
        int currentEnd = 0;
        int farthestNext = 0;
        int minIntervals = 0;
        int i = 0;
        while (i < clips.size() && currentEnd < time) {
            if (clips[i][0] > currentEnd) {
                return -1;
            }
            while (i < clips.size() && clips[i][0] <= currentEnd) {
                farthestNext = max(farthestNext, clips[i][1]);
                i++;
            }
            currentEnd = farthestNext;
            minIntervals++;
        }
        return currentEnd >= time ? minIntervals : -1;
    }
};