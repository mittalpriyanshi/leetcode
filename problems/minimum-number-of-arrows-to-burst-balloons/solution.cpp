class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(), points.end(), [](vector<int>&a ,vector<int>&b){
            return a[1]<b[1];
        });
        int arrows=1;
        int endTime = points[0][1];
        int i=0;
        while(i<n){
            if(points[i][0] > endTime){
                arrows++;
                endTime = points[i][1];
            }
            i++;
        }
        return arrows;
    }
};