// Source : https://leetcode.com/problems/gray-code/
// Author : Peiyang Hong
// Date   : 2015-10-06
// start  : 
/********************************************************************************** 
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 
algorithm:
	grayCode1 穷举所有的组合，并且判断相邻的元素是否只有一个元素不同 --> TLE
	grayCode2 事先计算每个与每个数相差一个数的组合 然后再遍历 相当于遍历一张无向图dfs -->TLE

**********************************************************************************/

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

#define DIFF_ONE_BIT(x,y) (!((x^y)&((x^y)-1)))

bool finish;
void dfs1(bool visit[], int n, vector<int>& seq, vector<int>& ret) {
	if (ret.size() == n+1) {
		finish = true;
		return;
	}
	int back = ret.back();
	for (int i = 1; i <= n; i++) {
		if (!visit[i] && DIFF_ONE_BIT(back, i)) {
			//cout<<i<<" "<<back<<endl;
			//cout<<((back^i)&((back^i)-1))<<endl;
			visit[i] = true;
			ret.push_back(i);
			dfs1(visit, n, seq, ret);
			if (finish) return;
			visit[i] = false;
			ret.pop_back();
		}
	}
}

vector<int> grayCode1(int n) {
	vector<int> seq;
	vector<int> ret;
	if (!n) return ret;
	n = pow(2, n) - 1;
	bool visit[n+1];
	for (int i = 1; i <= n; i++) {
		seq.push_back(i);
	}
	memset(visit, false, sizeof(bool)*n);
	finish = false;
	ret.push_back(0);
	dfs1(visit, n, seq, ret);
	return ret;
}

void dfs2(bool visit[], int n, vector<vector<int> >& seq, vector<int>& ret) {
	if (ret.size() == n+1) {
		finish = true;
		return;
	}
	int back = ret.back();
	for (int i = 0; i < seq[back].size(); i++) {
		int num = seq[back][i];
		if (!visit[num]) {
			visit[num] = true;
			ret.push_back(num);
			dfs2(visit, n, seq, ret);
			if (finish) return;
			visit[num] = false;
			ret.pop_back();
		}
	}
}
vector<int> grayCode2(int n) {
	
	vector<int> ret;
	if (!n) return ret;
	n = pow(2, n) - 1;

	vector<int> v;
	vector<vector<int> > seq(n+1, v);
	for (int i = 0; i <= n; i++) {
		for (int j = i+1; j <=n; j++) {
			if (DIFF_ONE_BIT(i, j)) {
				seq[i].push_back(j);
				seq[j].push_back(i);
			}
		}
	}
	bool visit[n+1];
	memset(visit, false, sizeof(bool)*n);
	visit[0] = true;
	finish = false;
	ret.push_back(0);
	dfs2(visit, n, seq, ret);
	return ret;
}

vector<int> grayCode(int n) {
	// TLE
	//return grayCode1(n);
	return grayCode2(n);
}

void print_vector(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	vector<int> ret;
	
	ret = grayCode(3);
	print_vector(ret);

	ret = grayCode(2);
	print_vector(ret);

	ret = grayCode(9);
	print_vector(ret);
}