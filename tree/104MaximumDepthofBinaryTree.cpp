// Source : https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Author : Peiyang Hong
// Date   : 2015-10-10
// start  : 
/********************************************************************************** 
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

**********************************************************************************/

class Solution {
public:
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        return max(dfs(root->left), dfs(root->right)) + 1;
    }
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};