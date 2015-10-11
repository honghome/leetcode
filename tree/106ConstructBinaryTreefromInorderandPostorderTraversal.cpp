// Source : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Author : Peiyang Hong
// Date   : 2015-10-11
// start  : 
/********************************************************************************** 
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

algorithm:
	根据中序和候选构建二叉树
	用后续的最后一个元素来分隔中序，然后递归调用

**********************************************************************************/

#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode *&root,
	     vector<int> &inorder, int il, int ir,
	     vector<int> &postorder, int pl, int pr) {
	if (il <= ir) {
		int val = postorder[pr--];
		for (int i = il; i <= ir; i++) {
			if (val == inorder[i]) {
				root = new TreeNode(val);
				int len = i - il;
				dfs(root->left, inorder, il, il+len-1, postorder, pl, pl+len-1);
				dfs(root->right, inorder, il+len+1, ir, postorder, pl+len, pr);
				break;
			}
		}
	}
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	TreeNode *root = NULL;
	if (inorder.size() == postorder.size()) {
		dfs(root, inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
	}
	return root;
}