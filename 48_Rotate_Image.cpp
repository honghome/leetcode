// Source : https://leetcode.com/problems/rotate-image/
// Author : Peiyang Hong
// Date   : 2015-09-10

/********************************************************************************** 

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
**********************************************************************************/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int> > tmp(n, vector<int>(n));
        int dp[n][n];
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                dp[j][n-i-1] = matrix[i][j];
            }
        }
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = dp[i][j];
            }
        }
    }
};