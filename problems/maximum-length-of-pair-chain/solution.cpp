class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; 
        });
        int currend = INT_MIN; 
        int chain = 0;
        for(int i=0;i<pairs.size();i++){
            int start=pairs[i][0];
            if(start> currend){
                currend = pairs[i][1];
                chain++;
            }
        }
        return chain;
    }
};