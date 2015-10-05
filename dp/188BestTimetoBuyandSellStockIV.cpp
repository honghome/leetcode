// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Author : Peiyang Hong
// Date   : 2015-09-20
/********************************************************************************** 
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

类似于123，操作次数最大为k，并且买之前一定要卖掉之前的

延用123的一个思路
states[][0]: one buy
states[][1]: one buy, one sell
states[][2]: two buys, one sell
states[][3]: two buys, two sells

states[][2*(k-1)]: k buys, k-1 sells
states[][2*(k-1) + 1]: buys, k sells


**********************************************************************************/
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int states[2][2*k];
        for (int i = 0; i < k; i ++) {
            states[0][2*k] = INT_MIN;
            states[0][2*k+1] = 0;
        }

        int cur = 0, next = 1;
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        //k = min(k, n);
        for (int i = 0; i < n; i++) {
            states[next][0] = max(states[cur][0], -prices[i]);
            states[next][1] = max(states[cur][1], states[cur][0] + prices[i]);
            for (int j = 1; j < k; j++) {
                states[next][2*j] = max(states[cur][2*j], states[cur][2*j-1] - prices[i]);
                states[next][2*j+1] = max(states[cur][2*j+1], states[cur][2*j] + prices[i]);
            }
            swap(cur, next);
        }
        int ret = 0;
        for (int i = 0; i < k; i ++) {
            ret = max(ret, states[cur][2*i+1]);
        }
        return ret;
    }
};


int main() {
    Solution so;
    int data[] = {1,2};
    vector<int> v(data,data+2);
    cout<<so.maxProfit(2,v)<<endl;

    return 0;
}