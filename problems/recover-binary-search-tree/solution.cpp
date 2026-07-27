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
TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *prev = NULL;
    void recoverTree(TreeNode* root) {
       TreeNode *curr =root;
        while(curr){
            if(!curr->left){
                helper(curr);
                curr = curr->right;
            }
            else{
                TreeNode* pred = curr->left;
                while(pred->right && pred->right!=curr) pred= pred->right; 
                if(pred->right == NULL)
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                else
                {
                    pred->right = NULL;
                    helper(curr);
                    curr = curr->right;
                }
            }
        }

        swap(first->val, second->val);
    }
    void helper(TreeNode* curr){
        if(prev && prev->val > curr->val){
            if(first==NULL) first = prev;
            second = curr;   
        }
        prev = curr;
    }
};