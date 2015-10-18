// Source : https://leetcode.com/problems/divide-two-integers/
// Author : Peiyang Hong
// Date   : 2015-10-12
// stars  : 4
/********************************************************************************** 

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

**********************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <stdio.h>
using namespace std;

int divide1(int dividend, int divisor) {
    int cnt = 0;
    bool flag = (dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0);
    int cur = divisor;
    dividend = abs(dividend);
    divisor = abs(divisor);
    while (dividend >= cur) {
        dividend -= divisor;
        cnt ++;
    }
    cnt = flag ? cnt : -cnt;
    return cnt;
}

// dividend = a0*2^0 + a1*2^1 + a2*2^2 + ... + an*2^n
// http://www.cnblogs.com/panda_lin/archive/2013/10/30/divide_two_integers.html
int divide2(int dividend, int divisor) {
    if (divisor == 0) {
        return INT_MAX;
    }
    // 2^0, 2^1, 2^2 ...
    int flag = ((dividend^divisor) >> 31) ? -1 : 1;
    long long ddend = abs((long long)dividend);
    long long dsor = abs((long long )divisor);
    long long base = dsor*1;
    long long cnt = 1;
    long long ret = 0;
    //cout<<"ddend: "<<ddend<<" "<<"dsor: "<<dsor<<endl;
    while (base <= ddend) {
        base <<= 1;
        cnt <<= 1;
        //cout<<"base: "<<base<<" "<<"cnt: "<<cnt<<endl;
    }
    while (ddend >= dsor) {
        while (ddend < base) {
            base >>= 1;
            cnt >>= 1;
        }
        ret += cnt;
        ddend -= base;
    }
    //cout<<"ret: "<<ret<<endl;
    //cout<<"INT_MAX: "<<INT_MAX<<endl;
    ret *= flag;
    ret = ret > INT_MAX ? INT_MAX : ret;
    return (int)ret;
}

int main() {
    int a, b;
    while(cin>>a>>b) {
        cout<<divide2(a,b)<<endl;
    }
    return 0;
}