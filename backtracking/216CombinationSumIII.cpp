// Source : https://leetcode.com/problems/combination-sum-iii/
// Author : Peiyang Hong
// Date   : 2015-10-06
// start  : 
/********************************************************************************** 
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]

note:
	1-9种的每个数字最多出现一次

algorithm:
	max(n) = (1+9)*9/2 = 45
	max(k) = 9
 
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
		 int target,
	     vector<int>& router,
	     vector<vector<int> >& ret) {

		if (target == 0) {
			if (router.size() == k) {
				ret.push_back(router);
			}
		} else {
			int len = max_num - start_num + 1;
			if (router.size() != k && router.size() + len >= k ) {
				for (int num = start_num; num <= max_num && num <= target; num++) {
					router.push_back(num);
					dfs(num+1, max_num, k, target-num, router, ret);
					router.pop_back();
				}
			}
		}
}

vector<vector<int> > combinationSum3(int k, int target)
{
	vector<vector<int> > ret;
	vector<int> router;
	if (k <=9 && target <= 45) {
		dfs(1, 9, k, target, router, ret);
	}
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
	
	ret = combinationSum3(3, 7);
	print_vector(ret);

	ret = combinationSum3(3, 9);
	print_vector(ret);
}