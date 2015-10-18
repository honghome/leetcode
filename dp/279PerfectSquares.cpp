// Source : https://leetcode.com/problems/perfect-squares/
// Author : Peiyang Hong
// Date   : 2015-10-12
// stars  : 4
/********************************************************************************** 

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
**********************************************************************************/
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

int numSquares(int n) {
    int dp[n+1];
    for (int i = 0; i <= n; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        dp[i*i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= sqrt(i); j++) {
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }
    return dp[n];
}

