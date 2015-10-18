// Source : https://leetcode.com/problems/sqrtx/
// Author : Peiyang Hong
// Date   : 2015-10-12
// stars  : 4
/********************************************************************************** 

Implement int sqrt(int x).

Compute and return the square root of x.

**********************************************************************************/

// binary search
int mySqrt1(int x) {
	int left = 0;
	int right = x;
	long long val;
	int mid;
	while (left <= right) {
		mid = right + ((left - right) >> 1);
		val = (long long)mid * (long long)mid;
		if (val == x) {
			return mid;
		}
		if (val < x) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return right;

}

const double EPS = 1e-8;
// newton method
// http://www.matrix67.com/blog/archives/361
// http://en.wikipedia.org/wiki/Newton%27s_method
int mySqrt2(int x) {
	if (x == 0) {
		return 0;
	}
	double last = 0;
	double res = 1;
	while (fabs(res - last) > EPS) {
		last = res;
		res = (res + x/res)/2;
	}
	return int(res);
}


