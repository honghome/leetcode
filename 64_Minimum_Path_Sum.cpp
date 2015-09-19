// Source : https://leetcode.com/problems/minimum-path-sum/
// Author : Peiyang Hong
// Date   : 2015-09-10

/********************************************************************************** 

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.


dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j]

**********************************************************************************/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m, n;
        m = grid.size();
        if (m > 0) {
            n = grid[0].size();
        } else {
            return 0;
        }
        int dp[m][n];
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (!i && !j) {
                    dp[i][j] = grid[i][j];
                } else if (!i) {
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                } else if (!j) {
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                } else {
                    dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m-1][n-1];
    }
};