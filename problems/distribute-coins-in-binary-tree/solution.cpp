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
int moves=0;
    int distributeCoins(TreeNode* root) {
        findCoins(root);
        return moves;
    }
    int findCoins(TreeNode* root){
        if(root==nullptr) return 0;
        int leftCoins = findCoins(root->left);
        int rightCoins = findCoins(root->right);

        moves += abs(leftCoins) + abs(rightCoins);
        return leftCoins + rightCoins + root->val -1;
    }
};