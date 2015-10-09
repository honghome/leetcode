// Source : https://leetcode.com/problems/combination-sum/
// Author : Peiyang Hong
// Date   : 2015-10-06
// start  : 
/********************************************************************************** 
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 

algorithm:
	枚举每一种可能，ai可以出现多次
	为了避免出现重复的组合，我们必须保证遍历序列(a1,a2,...,ak)的时候，所遍历到的数是不重复
**********************************************************************************/


#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

void dfs(vector<int>& c,
	     int id,
	     int target,
	     vector<int>& router,
	     vector<vector<int> >& ret) {

		if (target == 0) {
			ret.push_back(router);
		} else if (c[id] <= target){
			for (int i = id; i < c.size() && c[i] <= target; i++) {
				// skip duplicates
				if (i > id && c[i] == c[i-1]) {
					continue;
				}
				router.push_back(c[i]);
				dfs(c, i, target-c[i], router, ret);
				router.pop_back();
			}
		}
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target)
{
	vector<vector<int> > ret;
	vector<int> router;
	vector<int> sort_c(candidates);
	sort(sort_c.begin(), sort_c.end());
	dfs(sort_c, 0, target, router, ret);
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
	int data[] = {2,3,6,7};
	vector<vector<int> > ret;
	vector<int> c(data, data+4);
	ret = combinationSum(c, 7);
	print_vector(ret);
}