// Source : https://leetcode.com/problems/unique-binary-search-trees-ii/
// Author : Peiyang Hong
// Date   : 2015-10-05
// start  : 4
/********************************************************************************** 
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

algorithm:
    如果二叉树的组成是{left,root,right}, 那么把所有left的组成和right的组成做一个排列，并且以root为根节点
    就可以得到所有可能的组合
**********************************************************************************/


#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int s, int e) {
        vector<TreeNode*> ret;
        if (s > e) {
            ret.push_back(NULL);
        } else {
            for (int i = s; i <= e; i++) {
                vector<TreeNode*> vleft = generateTrees(s, i-1);
                vector<TreeNode*> vright = generateTrees(i+1, e);
                for (int l = 0; l < vleft.size(); l++) {
                    for (int r = 0; r < vright.size(); r++) {
                        TreeNode* root = new TreeNode(i);
                        root->left = vleft[l];
                        root->right = vright[r];
                        ret.push_back(root);
                    }
                }
            }
        }
        return ret;
    }
};

