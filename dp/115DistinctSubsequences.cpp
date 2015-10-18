// Source : https://leetcode.com/problems/distinct-subsequences/
// Author : Peiyang Hong
// Date   : 2015-10-06
// start  : 4
/********************************************************************************** 
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

algorithm:
	dp[i][j] s[0:i] 匹配 t[0:j]的个数
	
**********************************************************************************/




#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
    	int m = s.length();
    	int n = t.length();
    	if (!m || !n) return 0;

    	int dp[m][n];
    	for (int i = 0; i < m; i++) {
    		memset(dp[i], 0, sizeof(int)*n);	
    	}
    	dp[0][0] = s[0] == t[0] ? 1 : 0;
    	for (int i = 1; i < m; i++) {
    		dp[i][0] = s[i] == t[0] ? dp[i-1][0]+1 : dp[i-1][0];
    		for (int j = 1; j <= i && j < n; j++) {
    			if (s[i] == t[j]) {
    				// dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
    				if (dp[i-1][j])
    					dp[i][j] += dp[i-1][j] + 1;
    				if (dp[i-1][j-1])
    					dp[i][j] += dp[i-1][j-1];
    				if (dp[i-1][j] && dp[i-1][j-1])
    					dp[i][j] --;
    			} else {
    				dp[i][j] += dp[i-1][j];
    			}
    		}
    	}
    	return dp[m-1][n-1];
    }
};

int main() {
	string s, t;
	Solution so;
	while(cin>>s>>t) {
		cout<<so.numDistinct(s, t)<<endl;
	}
}