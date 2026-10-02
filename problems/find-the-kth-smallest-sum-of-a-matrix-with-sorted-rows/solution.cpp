class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n=mat[0].size();
        vector<int> initialRow= mat[0];
        for(int i=1;i<m;++i){
            vector<int> newSums;
            for(int j=0;j<n;++j){
                for(int num: initialRow){
                    newSums.push_back(num+ mat[i][j]);
                }
            }
            sort(newSums.begin(), newSums.end());
            initialRow.resize(min(k, int(newSums.size())));
            for(int l=0;l<min(k, int(newSums.size()));++l){
                initialRow[l] = newSums[l];
            }
        }
        return initialRow[k-1];
    }
};