// Source : https://leetcode.com/problems/decode-ways/
// Author : Peiyang Hong
// Date   : 2015-09-30
/********************************************************************************** 
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

algorithm:
dp[i] = dp[i-1] + dp[i-2]
如果在某个位置i dp[i] == 0 则结束dp 返回0

note:
两个数的范围是[20,26]
一个数的范围是[1,9]
**********************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
    	int n = s.length();
    	if (!n) return 0;
    	int dp[n];
    	dp[0] = (s[0] >= '1' && s[0] <= '9') ? 1 : 0;
    	for (int i = 1; i < n; i++) {
    		dp[i] = 0;
    		bool flag1 = false, flag2 = false;
    		// one
    		if (s[i] >= '1' && s[i] <= '9') {
    				dp[i] += dp[i-1];
    		}
    		// two
    		if (i > 0) {
    			int num = (s[i-1] - '0')*10 + (s[i] - '0');
    			if (num >= 10 && num <= 26) {
    				if (i == 1) {
    					dp[i] += 1;
    				} else {
    					dp[i] += dp[i-2];
    				}	
    			}
    		}
    		if (dp[i] == 0) {
    			return 0;
    		}
    	}
    	return dp[n-1];
    }
};