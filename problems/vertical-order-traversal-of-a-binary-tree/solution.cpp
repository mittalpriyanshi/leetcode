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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> nodes; //col,row,val
        dfs(root, nodes,0,0);
        sort(nodes.begin(), nodes.end());
        vector<vector<int>> res;
         int prevCol = INT_MIN;
        for(auto v:nodes){
            if(v[0] != prevCol){
                res.push_back({});
                prevCol= v[0];
            }
            res.back().push_back(v[2]);
        }
        return res;
    }
    void dfs(TreeNode* root,  vector<vector<int>>& nodes, int row, int col){
        if(!root) return;
        nodes.push_back({col,row,root->val});
        dfs(root->left, nodes, row+1, col-1);
        dfs(root->right, nodes, row+1, col+1);
    }
};