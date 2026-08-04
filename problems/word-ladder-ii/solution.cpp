class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        int n = wordList.size();
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hash;
        unordered_map<string, int> dist;
        dist[beginWord] = 0;
        vector<string> usedAtLevel;
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end())
            return {};
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string w = q.front();
                string curr = w;
                q.pop();
                if(curr == endWord) break;
                for (int i = 0; i < w.length(); i++) {
                    char org = w[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        w[i] = c;
                        if (st.find(w) != st.end()) {
                            if (dist.find(w) == dist.end()) {
                                dist[w] = dist[curr] + 1;
                                q.push(w);
                                hash[curr].push_back(w);
                                 usedAtLevel.push_back(w);
                            } else if (dist[w] == dist[curr] + 1) {
                                hash[curr].push_back(w);
                            }
                           
                        }
                    }
                    w[i] = org;
                }
            }
            for (auto& x : usedAtLevel)
                st.erase(x);
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