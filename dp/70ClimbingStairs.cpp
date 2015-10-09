// Source : https://leetcode.com/problems/climbing-stairs/
// Author : Peiyang Hong
// Date   : 2015-10-07
// start  : 

/********************************************************************************** 
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
**********************************************************************************/

#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

int climbStairs(int n) {
	int a[3];
	a[0] = 1;
	a[1] = 1;
	if (n < 0) return 0;
	if (n < 2) return 1;
	int id1 = 0, id2 = 1, id3 = 2;
	for (int i = 2; i <= n; i++) {
		a[id3] = a[id1] + a[id2];
		//cout<<a[id3]<<endl;
		id1 = (id1+1)%3;
		id2 = (id2+1)%3;
		id3 = (id3+1)%3;
	}
	return a[id2];
}

int main() {
	for (int i = 10; i <= 10; i++) {
		cout<<climbStairs(i)<<endl;
	}
}