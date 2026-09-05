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
int count=0;
    int distributeCoins(TreeNode* root) {
        findCoins(root);
        return count;
    }
    int findCoins(TreeNode* root){
        if(!root) return 0;
        int rightBalance = findCoins(root->right);
        int leftBalance = findCoins(root->left);
        count += abs(rightBalance) + abs(leftBalance);
        return leftBalance + rightBalance + root->val-1;
    }
};