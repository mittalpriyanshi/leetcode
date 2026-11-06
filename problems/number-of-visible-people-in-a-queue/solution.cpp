class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
    int n = heights.size();
    vector<int> res(n, 0);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() < heights[i]) {
            res[i]++;
            st.pop();
        }
        if (!st.empty()) {
            res[i]++;
        }
        st.push(heights[i]);
    }
    return res; 
    }
};