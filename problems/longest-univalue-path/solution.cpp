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
int maxLen = 0;
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return maxLen;
    }
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left_len = dfs(root->left);
        int right_len = dfs(root->right);
        int left_side=0, right_side=0;
        if(root->left && root->left->val==root->val) left_side = left_len+1;
        if(root->right && root->right->val==root->val) right_side = right_len+1;
        maxLen = max(maxLen, right_side+left_side);
        return max(right_side, left_side);
    }
};