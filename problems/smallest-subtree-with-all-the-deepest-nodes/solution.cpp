/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
    pair<TreeNode*,int> dfs(TreeNode* node){
        if(!node) return {nullptr, 0};
        auto [rightChild, dr] = dfs(node->right);
        auto [leftChild, dl]= dfs(node->left);
        if(dr==dl) return {node, dr+1};
        else if(dr>dl) return {rightChild, dr+1};
        else return {leftChild, dl+1};
    }
};