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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth ==1){
             TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while(!q.empty() && q.front().second < depth-1){
            auto [node, d] = q.front();
            q.pop();
            if(node->left) q.push({node->left, d+1});
            if(node->right) q.push({node->right, d+1});
        }
        while(!q.empty()){
            TreeNode* parentNode = q.front().first;
            q.pop();
            TreeNode* leftNode = parentNode->left;
            TreeNode* rightNode = parentNode->right;
            parentNode->left = new TreeNode(val);
            parentNode->left->left = leftNode;
            parentNode->right = new TreeNode(val);
            parentNode->right->right = rightNode;
        }
        return root;
    }
};