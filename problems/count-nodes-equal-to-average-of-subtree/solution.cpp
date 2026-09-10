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
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
    pair<int,int> dfs(TreeNode* root){
        if(!root) {
            return {0,0};
        }
        pair<int,int> right = dfs(root->right);
        pair<int,int> left = dfs(root->left);
        int sum = (right.first+left.first + root->val);
        int cnt =(right.second+left.second +1);
        if((sum / cnt) == root->val) count++;
        return {sum,cnt};
    }
};