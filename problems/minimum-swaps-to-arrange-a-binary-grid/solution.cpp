class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n =grid.size();
        vector<int> zeroes;
        for(int i=0;i<n;i++){
            int count=0;
            int j=n-1;
            while(j>=0 && grid[i][j]==0){
                count++;
                j--;
            }
            zeroes.push_back(count);
        }
        int swaps=0;
        for(int i=0;i<n;i++){
            int target = n-i-1;
            int j=i;
            while(j<n && zeroes[j]!=target) j++;
            if(j==n) return -1;
            swaps += j-i;
            while(j!=i){
                swap(zeroes[j], zeroes[j-1]);
                j--;
            }
        }
        return swaps;
    }
};