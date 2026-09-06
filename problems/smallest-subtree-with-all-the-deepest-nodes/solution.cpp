/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> mp;
        mp[root] = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> deepestLeaves;
        while (!q.empty()) {
            int size = q.size();
            deepestLeaves.clear();
            while (size--) {
                TreeNode* curr = q.front();
                deepestLeaves.push_back(curr);
                q.pop();
                if (curr->left) {
                    mp[curr->left] = curr;
                    q.push(curr->left);
                }
                if (curr->right) {
                    mp[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
        unordered_set<TreeNode*> set(deepestLeaves.begin(), deepestLeaves.end());
        while(set.size()>1){
            unordered_set<TreeNode*> LCA;
            for(auto node: set){
                LCA.insert(mp[node]);
            }
            set = LCA;
        }
        return *set.begin();
        // parent Map is populated, and we push nodes at that depth in the set
    }
};