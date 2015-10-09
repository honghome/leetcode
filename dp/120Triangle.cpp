// Source : https://leetcode.com/problems/triangle/
// Author : Peiyang Hong
// Date   : 2015-10-05

/********************************************************************************** 
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.


algorithm:
	dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j];

**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
    	vector<vector<int> > dp(triangle);
    	int n = triangle.size();
    	for (int i = 1; i < n; i++) {
    		for (int j = 0; j <= i; j++) {
	    		int a = j - 1 >= 0 ? dp[i-1][j-1] : INT_MAX;
	    		int b = j != i ? dp[i-1][j] : INT_MAX;
	    		dp[i][j] += min(a, b);
	    		//cout<<dp[i][j]<<endl;
    		}
    	}
    	int ret = INT_MAX;
    	for (int i = 0; i < n; i++) {
    		ret = min(ret, dp[n-1][i]);
    	}
    	return ret;
    }
};