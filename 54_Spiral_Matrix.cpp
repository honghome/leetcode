// Source : https://oj.leetcode.com/problems/powx-n/
// Author : Peiyang Hong
// Date   : 2015-09-10

/********************************************************************************** 

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

蛇形打印矩阵元素

思路：对矩阵的四个角设定坐标点，然后一次打印四条边，然后更新坐标点
注意：打印down 和 left的时候 要判断是否可以打印
**********************************************************************************/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ret;
        int m = matrix.size();
        if (m == 0)
        	return ret;
        int n = matrix[0].size();

        if (n == 0)
        	return ret;

        int rowStart = 0, rowEnd = m - 1;
        int cloStart = 0, cloEnd = n - 1;

        int cnt = m * n;
        while (ret.size() < cnt) {
        	//up
        	for (int i = cloStart; i <= cloEnd; i++) {
        		ret.push_back(matrix[rowStart][i]);
        	}

        	//right
        	for (int i = rowStart + 1; i <= rowEnd - 1 ; i++) {
        		ret.push_back(matrix[i][cloEnd]);
        	}

        	// down
        	if (rowStart < rowEnd) {
	        	for (int i = cloEnd; i >= cloStart; i --) {
	        		ret.push_back(matrix[rowEnd][i]);
	        	}
	        }

        	// left
	        if (cloStart < cloEnd) {
	        	for (int i = rowEnd - 1; i >= rowStart + 1; i --) {
	        		ret.push_back(matrix[i][cloStart]);
	        	}
	        }

        	rowStart ++;
        	rowEnd --;
        	cloStart ++;
        	cloEnd --;
        }
        return ret;
    }
};