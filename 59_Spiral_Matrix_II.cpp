// Source : https://oj.leetcode.com/problems/powx-n/
// Author : Peiyang Hong
// Date   : 2015-09-10

/********************************************************************************** 
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

打印蛇形矩阵

**********************************************************************************/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ret(n, vector<int>(n, 0));
        if (n <= 0)
        	return ret;
        int rowStart = 0, rowEnd = n-1;
        int cloStart = 0, cloEnd = n-1;
        int num = 1;
        while (rowStart <= rowEnd) {
        	for (int i = cloStart; i <= cloEnd; i ++)
        		ret[rowStart][i] = num ++;

        	for (int i = rowStart+1; i <= rowEnd-1; i ++)
        		ret[i][cloEnd] = num ++;
        	
        	if (rowStart < rowEnd) {
        		for (int i = cloEnd; i >= cloStart; i --)
        			ret[rowEnd][i] = num ++;
        	}
        	
        	if (cloStart < cloEnd) {
        		for (int i = rowEnd - 1; i >= rowStart + 1; i --)
        			ret[i][cloStart] = num ++;
        	}
        	rowStart ++;
        	rowEnd --;
        	cloStart ++;
        	cloEnd --;
        }
        return ret;
    }
};