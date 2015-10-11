// Source : https://leetcode.com/problems/binary-tree-preorder-traversal/
// Author : Peiyang Hong
// Date   : 2015-10-11
// start  : 
/********************************************************************************** 
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
    

**********************************************************************************/
class Solution {
public:
    void dfs(TreeNode *root, vector<int> &path) {
        if (root) {
            path.push_back(root->val);
            dfs(root->left, path);
            dfs(root->right, path);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> path;
        dfs(root, path);
        return path;
    }
};