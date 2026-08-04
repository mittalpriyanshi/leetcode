class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        int n = wordList.size();
        if (wordList[n - 1] != endWord)
            return {};
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hash;
        set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        st.erase(beginWord);
        while (!q.empty()) {
            string w = q.front();
            string orgW = w;
            q.pop();
            for (int i = 0; i < w.length(); i++) {
                char org = w[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    w[i] = c;
                    if (st.find(w) != st.end()) {
                        st.erase(w);
                        q.push(w);
                        hash[orgW].push_back(w);
                    }
                }
                w[i] = org;
            }
        }
        vector<string> temp;
        temp.push_back(beginWord);
        make(res, hash, beginWord, endWord, temp);
        return res;
        // now we have kind of an adjacency list in form of hash map
    }

    void make(vector<vector<string>>& res,
              unordered_map<string, vector<string>>& hash, string beginWord,
              string endWord, vector<string>& temp) {
        if (beginWord == endWord) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < hash[beginWord].size(); i++) {
            temp.push_back(hash[beginWord][i]);
            make(res, hash, hash[beginWord][i], endWord, temp);
            temp.pop_back();
        }
        return;
    }
};