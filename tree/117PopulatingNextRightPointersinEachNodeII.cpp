// Source : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Author : Peiyang Hong
// Date   : 2015-10-10
// start  : 
/********************************************************************************** 
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL



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
    if (root->left) {
        dfs(root->left, prev, dist-1);
    }
    if (root->right) {
        dfs(root->right, prev, dist-1);
    }
}

int get_height(TreeLinkNode *root) {
    if (root == NULL) {
        return 0;
    }
    return max(get_height(root->left), get_height(root->right)) + 1;
}

void connect(TreeLinkNode* root) {
    TreeLinkNode *prev;
    int depth;
    depth = get_height(root);
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
    connect(root);
}

