// Source : https://leetcode.com/problems/unique-paths-ii/
// Author : Peiyang Hong
// Date   : 2015-09-10

/********************************************************************************** 

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100

思路：

dp[i][j] = -1 if unreached
dp[i][j] += dp[i-1][j] if dp[i-1][j] !=-1
dp[i][j] += dp[i][j-1] if dp[i][j01] !=-1

dp[0][0] == -1 || dp[m-1][n-1] == -1 --> return 0
**********************************************************************************/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m, n;
        m = obstacleGrid.size();
        if (m > 0)
            n = obstacleGrid[0].size();
        else
            return 0;
            
        int dp[m][n];
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (obstacleGrid[i][j]) {
                    dp[i][j] = -1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        if (dp[0][0] == -1 || dp[m-1][n-1] == -1) {
            return 0;
        }
        dp[0][0] = 1;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j++) {
                if((!i && !j) || dp[i][j] == -1) {
                    continue;
                }
                dp[i][j] += (i - 1 >=0 && dp[i-1][j] != -1) ? dp[i-1][j] : 0;
                dp[i][j] += (j - 1 >=0 && dp[i][j-1] != -1) ? dp[i][j-1] : 0;
            }
        }
        
        return dp[m-1][n-1];
    }
};