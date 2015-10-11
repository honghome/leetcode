// Source : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Author : Peiyang Hong
// Date   : 2015-10-10
// start  : 
/********************************************************************************** 
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree 
(ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

algorithm:
	1.按照题意，给定的树是一棵满二叉树，每一层的叶子节点的个数时确定的，
	于是我们借助队列，对这棵树进行层次便利，并且将同一层的节点保存在连续的位置
	然后更新每个层次的next指针，空间复杂度是O(n)
	
	2.如果不用扶住空间的话


**********************************************************************************/

#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect1(TreeLinkNode *root) {
	if (!root) return;
	vector<TreeLinkNode*> que;
	que.push_back(root);
	int level = 0;
	int level_cnt = 1;
	for (int i = 0; i < que.size(); i++) {
		TreeLinkNode* cur = que[i];
		level_cnt --;
		if (level_cnt == 0) {
			cur->next = NULL;
			level ++;
			level_cnt = pow(2, level);
		} else {
			cur->next = que[i+1];
		}
		if (cur->left) {
			que.push_back(cur->left);
		}
		if (cur->right) {
			que.push_back(cur->right);
		}
	}
}

void dfs(TreeLinkNode *root, TreeLinkNode *&prev, int dist) {
	if (dist <= 0) {
		if (prev == NULL) {
			prev = root;
		} else {
			prev->next = root;
			prev = prev->next;
		}
		return;
	}
	dfs(root->left, prev, dist-1);
	dfs(root->right, prev, dist-1);
}

void connect2(TreeLinkNode* root) {
	TreeLinkNode *prev, *p;
	int depth = 0;
	p = root;
	while(p) {
		p->next = NULL;
		p = p->right;
		depth++;
	}
	for (int i = 0; i < depth; i++) {
		prev = NULL;
		dfs(root, prev, i);
	}
}

void construct_tree(vector<int>& nums, TreeLinkNode *&root, int id) {
	if (id < nums.size()) {
		int num = nums[id];
		if (num != -1) {
			root = new TreeLinkNode(num);
			construct_tree(nums, root->left, 2*id+1);
			construct_tree(nums, root->right, 2*id+2);
		}
	}
}

int main() {
	int data[] = {0,1,2,3,4,5,6};
	vector<int> v(data, data+7);
	TreeLinkNode* root;
	construct_tree(v, root, 0);
	connect2(root);
}





