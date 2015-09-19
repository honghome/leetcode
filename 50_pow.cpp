// Source : https://oj.leetcode.com/problems/powx-n/
// Author : Peiyang Hong
// Date   : 2015-09-10

/********************************************************************************** 

Implement pow(x, n).

1. 考虑n为负数的情况
2. 加速指数运算的方法：
	    pow(1, MAX_INT);
	    pow(1, MIN_INT);    --> unsigned exp = n
 	    pow(-1,BIG_INT);
        pow(2, BIG_INT);

	if `n` is an even number,  `x = x*x`, and `n = n>>1;`
	if `n` is an odd number,  `result *= x;`

**********************************************************************************/



class Solution {
public:
    double myPow(double x, int n) {

    	bool sign = false;
    	unsigned int exp = n;
    	if (n < 0) {
    		exp = -exp;
    		sign = true;
    	}
    	double result = 1.0;
    	while (exp) {
    		if (exp & 1) {
    			result *= x;
    		}
    		exp >>= 1;
    		x *= x;
    	}
    	return sign ? 1/result : result;
    }
};