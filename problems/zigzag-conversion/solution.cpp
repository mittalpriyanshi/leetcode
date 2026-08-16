class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows == 1 || n <= 1) return s; 
        
        int eachInterval = 2 * numRows - 2;
        int blocks = n / eachInterval + 1;
        
        vector<vector<char>> matrix(numRows,
                                    vector<char>(blocks * (numRows - 1), '_'));
        int k = 0;
        int i = 0, j = 0;
        
        while (k < n) {
            // Downward column
            while (k < n && i < numRows) {
                matrix[i][j] = s[k];
                k++;
                i++;
            }
            
            // Adjust pointers to start the upward diagonal
            if (i == numRows) {
                i -= 2;
                j++;
            }
            
            //Stop at i > 0 so we don't handle the top row during the diagonal
            while (k < n && i > 0) {
                matrix[i][j] = s[k];
                k++;
                j++;
                i--;
            }
            
        }
        
        string res = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < blocks * (numRows - 1); j++) {
                if (matrix[i][j] != '_')  res += matrix[i][j];
            }
        }
        
        return res;
    }
};