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
 int cameras =0;
 // 0 = not covered
    // 1 = covered, no camera
    // 2 = has camera
    int dfs(TreeNode* root){
        if(root==NULL) return 1;
        int left = dfs(root->left);
        int right = dfs(root->right);
         //if child not covered, put camera at curr node
        if(left==0 || right==0){
            cameras++;
            return 2;
            
        }
        //any of the child has cam, so the curr node is covered
        if(left==2 || right==2){
            return 1;
        } 
        //both child are covered but they do not have cam so curr node is not covered
        return 0;
    }
     int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) cameras++;
        return cameras;
    }
};