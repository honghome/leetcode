// Source : https://leetcode.com/problems/combination-sum-iii/
// Author : Peiyang Hong
// Date   : 2015-10-06
// start  : 
/********************************************************************************** 
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

algorithm:
	计算所有可能的组合

 
**********************************************************************************/

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

void dfs(int start_num,
	     int max_num,
	     int k,
	     vector<int>& router,
	     vector<vector<int> >& ret) {

		if (router.size() == k) {
			ret.push_back(router);
		} else if (router.size() != k) {
			int size = router.size();
			//max_num - num + 1  + size >= k
			for (int num = start_num;
				 num <= max_num && num <= max_num + size - k + 1;
				 num++) {
				router.push_back(num);
				dfs(num+1, max_num, k, router, ret);
				router.pop_back();
			}
		}
}

vector<vector<int> > combine(int n, int k) {
	vector<vector<int> > ret;
	vector<int> router;
	if (n < k ||  n < 1 || k < 1) return ret;

	dfs(1, n, k, router, ret);
	return ret;
}

void print_vector(vector<vector<int> >& ret) {
	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++) {
			cout<<ret[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	vector<vector<int> > ret;
	
	ret = combine(4, 2);
	print_vector(ret);

	ret = combine(5, 2);
	print_vector(ret);
}