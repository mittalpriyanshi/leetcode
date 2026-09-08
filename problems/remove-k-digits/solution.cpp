class Solution {
public:
    string removeKdigits(string num, int k) {
        int n =num.size();
        stack<char> st;
        for(char d:num){
            while(!st.empty() && k>0 && st.top() > d){
                st.pop();
                k--;
            }
            st.push(d);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        string res;
        while(!st.empty()){
            res +=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        size_t pos = res.find_first_not_of('0');
        res = (pos == string::npos) ? "0": res.substr(pos);
        return res;
    }
};