// Source : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Author : Peiyang Hong
// Date   : 2015-10-11
// start  : 
/********************************************************************************** 
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

algorithm:
	根据前序和中序构建二叉树，则前序的第一个元素位于中序的中间
	顺序遍历preorder, 每一次迭代呢都将当前的inorder[il, ir]分成两个部分，然后再递归构建

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
	     vector<int>& preorder, int &id,
	     vector<int>& inorder, int il, int ir) {
	if (id < preorder.size() && il <= ir) {
		int val = preorder[id];
		root = new TreeNode(val);
		id++;
		for (int i = il; i <= ir; i++) {
			if (val == inorder[i]) {
				dfs(root->left, preorder, id, inorder, il, i-1);
				dfs(root->right, preorder,  id, inorder, i+1, ir);
				break;
			}
		}
	}
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
	TreeNode *root = NULL;
	if (preorder.size() == inorder.size()) {
		int id = 0;
		dfs(root, preorder, id, inorder, 0, inorder.size()-1);
	}
	return root;
}


