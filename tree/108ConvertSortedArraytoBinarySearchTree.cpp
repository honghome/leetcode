// Source : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Author : Peiyang Hong
// Date   : 2015-10-09
// start  : 
/********************************************************************************** 
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.


algorithm:
	mid = (left+right)>>1;
	以mid为root，左右两分分别递归构造

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

void create_bst(vector<int>& nums, TreeNode*& root, int left, int right) {
	if (left <= right) {
		int mid = (left + right) >> 1;
		root = new TreeNode(nums[mid]);
		create_bst(nums, root->left, left, mid-1);
		create_bst(nums, root->right, mid+1, right);
	}
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	TreeNode* root = NULL;
	create_bst(nums, root, 0, nums.size()-1);
	return root;
}

void print_bst(TreeNode* root) {
	if (root) {
		print_bst(root->left);
		cout<<root->val<<endl;
		print_bst(root->right);
	}
}

bool is_balance(TreeNode *root, int& height) {
	if (root) {
		int hl, hr;
		bool bl, br;
		bl = is_balance(root->left, hl);
		br = is_balance(root->right, hr);
		height = max(hl, hr) + 1;
		return bl && br;
	}
	height = 0;
	return true;
}

int main() {
	int data[] = {1,3,5,6,7,8,9};
	//vector<int> v(data, data+7);
	vector<int> v;
	TreeNode* root = sortedArrayToBST(v);
	print_bst(root);
	int height;
	bool balance;
	balance = is_balance(root, height);
	cout<<"is balalce: "<<balance<<endl;
	cout<<"height: "<<height<<endl;
}