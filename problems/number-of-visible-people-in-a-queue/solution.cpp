class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
    vector<int> res(n,0);
    for(int i = 0; i < n; i++) {
        int maxh = 0;
        for(int j = i + 1; j < n; j++) {
            if(heights[j] > maxh) {
                res[i]++;
            }
            maxh = max(maxh, heights[j]);
            if(heights[j] > heights[i]) {
                break;
            }
        }
    }
    return res;
        
    }
};