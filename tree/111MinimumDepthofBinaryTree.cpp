// Source : https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Author : Peiyang Hong
// Date   : 2015-10-10
// start  : 
/********************************************************************************** 
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

algorithm:
	注意与max的区别，一次wa的例子
		Input:
		[1,2]
		Output:
		1
		Expected:
		2
**********************************************************************************/
class Solution {
public:
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        if (!root->left) return dfs(root->right) + 1;
        if (!root->right) return dfs(root->left) + 1;
        return min(dfs(root->left), dfs(root->right)) + 1;
    }
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};