// Source : https://leetcode.com/problems/path-sum-ii/
// Author : Peiyang Hong
// Date   : 2015-10-10
// start  : 
/********************************************************************************** 
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

algorithm:
	// 求的是从根节点到叶节点的路径，val可以为负数，所以只能到叶子节点才能知道sum是否符合要求
	// 这是一道简单的题目，但是却错了很多次

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

void dfs(TreeNode* root, int left, vector<int> &path, vector<vector<int> > &ret) {
	if (root) {
		int val = root->val;
		left -= val;
		path.push_back(val);
		if (!root->left && !root->right) {
			if (left == 0) {
				ret.push_back(path);
			}
		} else {
			dfs(root->left, left, path, ret);
			dfs(root->right, left, path, ret);
		}
		path.pop_back();
	}
}

vector<vector<int> > pathSum(TreeNode* root, int sum) {
	vector<vector<int> > ret;
	vector<int> path;
	dfs(root, sum, path, ret);
	return ret;
}

void construct_tree(vector<int>& nums, TreeNode *&root, int id) {
    if (id < nums.size()) {
        int num = nums[id];
        if (num != -1) {
            root = new TreeNode(num);
            construct_tree(nums, root->left, 2*id+1);
            construct_tree(nums, root->right, 2*id+2);
        }
    }
}

void print_vector_1(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout<<v[i]<<" ";
	}
}
void print_vector_2(vector<vector<int> > v) {
	cout<<"size: "<<v.size()<<endl;
	for (int i = 0; i < v.size(); i++) {
		print_vector_1(v[i]);
		cout<<endl;
	}
}
int main() {
    int data[] = {-2,-1,-3};
    vector<int> v(data, data+3);
    TreeNode* root;
    construct_tree(v, root, 0);
    vector<vector<int> > ret;
    ret = pathSum(root, -5);
    print_vector_2(ret);
}
