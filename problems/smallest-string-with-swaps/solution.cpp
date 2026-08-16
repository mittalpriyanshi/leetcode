class dsu {
public:
    vector<int> parent;
    vector<int> size;
    dsu(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int findPar(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = findPar(parent[x]);
    }
    void unite(int a, int b) {
        int parent1 = findPar(a);
        int parent2 = findPar(b);
        if (parent1 == parent2)
            return;
        if (size[parent1] < size[parent2])
            swap(parent1, parent2);
        parent[parent2] = parent1;
        size[parent1] += size[parent2];
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        dsu con(n);
        for (auto v : pairs)
            sort(v.begin(), v.end());
        for (auto& pair : pairs) {
            con.unite(pair[0], pair[1]);
        }
        string ans(n, '.');
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            int root = con.findPar(i);
            mp[root].push_back(i);
        }
        for (auto& [root, indices] : mp) {
            string chars = "";
            for (int idx : indices) {
                chars += s[idx];
            }

            sort(chars.begin(), chars.end());
            for (int j = 0; j < indices.size(); j++) {
                ans[indices[j]] = chars[j];
            }
        }
        return ans;
    }
};