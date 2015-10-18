// Source : https://leetcode.com/problems/restore-ip-addresses/
// Author : Peiyang Hong
// Date   : 2015-10-06
// start  : 
/********************************************************************************** 
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

algorithm:
	按照题意，我们需要计算四个点可能存在的位置，从左到右标号(0,1,2)
	判定的标准是:
		放置第i个点之后，之后的字符串的长度的范围   (3-i)<=len <= (3-i)*4
 a.a.a.a
**********************************************************************************/

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

void dfs(string& s, int id, int n, vector<int>& pos, vector<string>& ret) {
	int i = id;
	int l = s.length();
	while (n-i <= l-i-1 && l )
}
vector<string> restoreIpAddresses(string s) {
	vector<string> ret;
	vector<int> pos;
	dfs(s, id, pos, ret);
}

int main()
{
	vector<vector<int> > ret;
	
	ret = combine(4, 2);
	print_vector(ret);

	ret = combine(5, 2);
	print_vector(ret);
}