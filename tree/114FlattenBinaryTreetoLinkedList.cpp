// Source : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author : Peiyang Hong
// Date   : 2015-10-09
// start  : 
/********************************************************************************** 
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to 
the next node of a pre-order traversal.


algorithm:
	边递归便利边实现：
		生成的flatten是由左子树的flatten 和 右子树的flatten链接而成的
		为了进行链接，需要记录子树flatten的最后一个节点
		左后根据左右子数是否为空来链接

	前序遍历玩所有的节点之后，再按顺序将各个节点串联起来

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

void get_flatten(TreeNode* root, TreeNode*& tail) {
	if (root) {
		TreeNode *ltail, *rtail;
		ltail = rtail = NULL;
		get_flatten(root->left, ltail);
		get_flatten(root->right, rtail);
		if (ltail) {
			ltail->right = root->right;
			root->right = root->left;
			tail = rtail ? rtail : ltail;
			root->left = NULL;
		} else {
			tail = rtail ? rtail : root;
		}
	}
}

void get_flatten(TreeNode* root) {

	if (!root) {
		return;
	}

	vector<TreeNode*> v, stack;
	stack.push_back(root);
	while(stack.size() > 0) {
		TreeNode* node = stack.back();
		stack.pop_back();
		v.push_back(node);

		if (node->right) {
			stack.push_back(node->right);
		}

		if (node->left) {
			stack.push_back(node->left);
		}
	}

	v.push_back(NULL);

	for (int i = 0; i < v.size() - 1; i++) {
		v[i]->left = NULL;
		v[i]->right = v[i+1];
	}
}

void flatten(TreeNode* root) {
	TreeNode* tail;
	//get_flatten(root, tail);
	get_flatten(root);
}

bool is_flatten(TreeNode* root) {
	TreeNode* p = root;
	cout<<"[";
	while (p) {
		if (p->left) return false;
		cout<<" "<<p->val;
		p = p->right;
	}
	cout<<"]"<<endl;
	return true;
}

void construct_tree(vector<int>& nums, TreeNode*& root, int id) {
	if (id < nums.size()) {
		int num = nums[id];
		if (num != -1) {
			root = new TreeNode(num);
			construct_tree(nums, root->left, 2*id+1);
			construct_tree(nums, root->right, 2*id+2);
		}
	}
}

int main() {
	//int data[] = {1,2,5,3,4,-1,6};
	int data[] = {1,2,5,-1,4,-1,6};
	vector<int> v(data, data+7);
	TreeNode* root;
	construct_tree(v, root, 0);
	flatten(root);
	cout<<is_flatten(root);
}
