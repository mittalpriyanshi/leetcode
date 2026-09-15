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
class Node{
    public :
    int maxNode,minNode,Sum;

    Node(int minNode,int maxNode,int Sum){
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->Sum = Sum;
    }
};
class Solution {
public:
    int ans = 0;
    Node helper(TreeNode* root){
        if(!root) return Node(INT_MAX,INT_MIN,0);
        auto left = helper(root->left);
        auto right = helper(root->right);
// valid bst conditionn
        if(left.maxNode < root->val && right.minNode > root->val){
            int curSum = left.Sum + right.Sum + root->val; 
            ans = max(ans,curSum);
            return Node(min(root->val,left.minNode),max(root->val,right.maxNode),curSum);
        }
        return Node(INT_MIN,INT_MAX,0);
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};