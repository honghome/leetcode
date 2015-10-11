// Source : https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Author : Peiyang Hong
// Date   : 2015-10-10
// start  : 
/********************************************************************************** 
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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

void get_sumNumbers(TreeNode *root, int cur_num, int &sum) {
	if (!root) {
		return;
	}
	cur_num = cur_num*10 + root->val;
	if (!root->left && !root->right) {
		sum += cur_num;
	} else {
		if (root->left) {
			get_sumNumbers(root->left, cur_num, sum);
		}
		if (root->right) {
			get_sumNumbers(root->right, cur_num, sum);
		}
	}
}

int sumNumbers(TreeNode* root) {
	int sum = 0;
	get_sumNumbers(root, 0, sum);
	return sum;
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
	int data[] = {1,2,5,3};
	vector<int> v(data, data+4);
	TreeNode* root;
	construct_tree(v, root, 0);
	cout<<sumNumbers(root)<<endl;
}