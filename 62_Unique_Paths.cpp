// Source : https://leetcode.com/problems/unique-paths/
// Author : Peiyang Hong
// Date   : 2015-09-10

/********************************************************************************** 


A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


动态规划
dp[0][0] = 1;
dp[i][j] = dp[i-1][j] + dp[i][j-1]

**********************************************************************************/


class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        
        dp[0][0] = 1;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n ; j ++) {
                if (!i && !j) {
                    continue;
                }
                dp[i][j] = (i - 1 >= 0) ? dp[i-1][j] : 0;
                dp[i][j] += (j - 1 >= 0) ? dp[i][j-1] : 0; 
            }
        }
        return dp[m-1][n-1];
    }
};