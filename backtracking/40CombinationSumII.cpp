// Source : https://leetcode.com/problems/combination-sum-ii/
// Author : Peiyang Hong
// Date   : 2015-10-06
// start  : 
/********************************************************************************** 
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 


1. 每个位置的元素不能重复出现
2. 所有的组合必须是唯一的


algorithm:
	每一层所枚举的元素不能重复
	每个位置的元素只能枚举一次

**********************************************************************************/


#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
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
				// skip duplicates on same level
				if (i > id && c[i] == c[i-1]) {
					continue;
				}
				router.push_back(c[i]);
				dfs(c, i+1, target-c[i], router, ret);
				router.pop_back();
			}
		}
}

vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
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
	int data[] = {10,1,2,7,6,1,5};
	vector<vector<int> > ret;
	vector<int> c(data, data+7);
	ret = combinationSum2(c, 8);
	print_vector(ret);
}