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
int maxLen=0;
    int longestZigZag(TreeNode* root) {
        dfs(root->left, true, 1);
        dfs(root->right, false, 1);
        return maxLen;
    }
    void dfs(TreeNode* root, bool isLeft, int steps){
        if(!root) return;
        maxLen = max(maxLen, steps);
        if(isLeft){
            dfs(root->right, false, steps+1);
            dfs(root->left, true, 1);
        }
        else{
            dfs(root->left, true, steps+1);
            dfs(root->right, false, 1);
        }
    }
};