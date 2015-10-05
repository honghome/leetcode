// Source : https://leetcode.com/problems/word-break/
// Author : Peiyang Hong
// Date   : 2015-10-04

/********************************************************************************** 
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

algorithm:
dp[i] = dp[j] && s[j+1,i] in wordDict
o(n^2)

**********************************************************************************/

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
    	int n = s.length();
    	if (!n) return false;
    	bool dp[n];
    	for (int i = 0; i < n; i++) {
    		if (wordDict.find(s.substr(0, i+1)) != wordDict.end()) {
    			dp[i] = true;
    			continue;
    		}
    		dp[i] = false;
    		for (int j = i; j > 0; j--) {
    			if (dp[j-1] && wordDict.find(s.substr(j, i-j+1)) != wordDict.end()) {
    				dp[i] = true;
    				break;
    			}
    		}
    	}
    	return dp[n-1];
    }
};