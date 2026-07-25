class DSU {
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findUlPar(int idx) {
        if (parent[idx] == idx)
            return idx;
        return parent[idx] = findUlPar(parent[idx]);
    }
    void doUnion(int idx1, int idx2) {
        int p1 = findUlPar(idx1);
        int p2 = findUlPar(idx2);
        if (p1 == p2)
            return;
        if (size[p1] > size[p2]) {
            parent[p2] = p1;
            size[p1] += size[p2];
        } else {
            parent[p1] = p2;
            size[p2] += size[p1];
        }
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        DSU con(100001);
        for (auto num : nums) {
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    con.doUnion(num, i);
                    con.doUnion(num, num / i);
                }
            }
        }
        unordered_map<int, int> sizes;
        for (auto num : nums) {
            int root = con.findUlPar(num);
            sizes[root]++;
        }

        int maxSize = 1;
        for (auto p : sizes) {
            maxSize = max(maxSize, p.second);
        }

        return maxSize;
    }
};