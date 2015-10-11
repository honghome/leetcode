// Source : https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author : Peiyang Hong
// Date   : 2015-10-11
// start  : 
/********************************************************************************** 
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].
    

**********************************************************************************/

class Solution {
public:
    void dfs(TreeNode* root, vector<int> &path) {
        if (root) {
            dfs(root->left, path);
            path.push_back(root->val);
            dfs(root->right, path);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> path;
        dfs(root, path);
        return path;
    }
};