class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> prefix=mat;
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                prefix[i][j] += prefix[i][j - 1];

        for (int j = 0; j < m; j++)
            for (int i = 1; i < n; i++)
                prefix[i][j] += prefix[i - 1][j];
                int low =1, high = min(n,m);
                int ans=0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isValid(prefix, mid, threshold)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
    bool isValid(vector<vector<int>>& prefix, int k, int threshold){
        int n = prefix.size();
        int m = prefix[0].size();
         for (int i = k - 1; i < n; i++) {
            for (int j = k - 1; j < m; j++) {
                int x1 = i - k + 1;
                int y1 = j - k + 1;
                int sum = prefix[i][j]
                        - (x1 > 0 ? prefix[x1 - 1][j] : 0)
                        - (y1 > 0 ? prefix[i][y1 - 1] : 0)
                        + (x1 > 0 && y1 > 0 ? prefix[x1 - 1][y1 - 1] : 0);

                if (sum <= threshold)
                    return true;
            }
        }
        return false;
    }
};