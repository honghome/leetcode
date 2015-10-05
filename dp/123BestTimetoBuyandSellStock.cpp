// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Author : Peiyang Hong
// Date   : 2015-09-20

/********************************************************************************** 
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

错误思路1:
类似于122，由于要求最多操作两次，我们可以分别记录 最大 和 第二大的值
这个想法是错的

Input:
[1,2,4,2,5,7,2,4,9,0]
Output:
12
Expected:
13

思路1
这道题了只交易一次的要求类似，在那道题中，我们通过从后向前扫描来得到一组最大的差值
延用那道题的思路，我们寻找两对差值，使得它们的和的差值最大，并且取得两对差值的区间不重合

dp_buy[i] 表示在[0,i]时刻至多买一次股票所能获得的最大利润
dp_sell[i] 表示在[i,n-1]时刻至多卖股票所能获得的最大利润

ret =  max(dp_sell[i], dp_buy[j]), i < j

time: o(n)
space: o(n)

思路2
https://leetcode.com/discuss/48151/my-c-solution-o-n-time-o-1-space-8ms

It is similar to other buy/sell problems. 
just do DP and define an array of states to track the current maximum profits at different stages. 
For example, in the below code

states[][0]: one buy
states[][1]: one buy, one sell
states[][2]: two buys, one sell
states[][3]: two buy, two sells
The states transistions occurs when buy/sell operations are executed. 
For example, state[][0] can move to state[][1] via one sell operation.

**********************************************************************************/
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp_buy[prices.size()];
        int dp_sell[prices.size()];
        if (n < 1) {
            return 0;
        }

        int cur_min_price = prices[0];
        int cur_max_profit = 0;
        dp_sell[0] = 0;
        for(int i = 1; i < n; i ++) {
            if (cur_min_price >= prices[i]) {
                dp_sell[i] = 0;
                cur_min_price = prices[i];
            } else {
                dp_sell[i] = prices[i] - cur_min_price;
            }
            if (dp_sell[i] >= cur_max_profit) {
                cur_max_profit = dp_sell[i];
            } else {
                dp_sell[i] = cur_max_profit;
            }
        }

        int cur_max_price = prices[n-1];
        cur_max_profit = 0;
        dp_buy[n-1] = 0;
        for(int i = n-2; i >=0; i --) {
            if (cur_max_price <= prices[i]) {
                dp_buy[i] = 0;
                cur_max_price = prices[i];
            } else {
                dp_buy[i] = cur_max_price - prices[i];
            }
            if (dp_buy[i] >= cur_max_profit) {
                cur_max_profit = dp_buy[i];
            } else {
                dp_buy[i] = cur_max_profit;
            }
        }

        //for (int i = 0; i < n; i ++)
        //   cout<<dp_sell[i]<<" "<<dp_buy[i]<<endl;
        int ret = 0;
        for(int i = 0; i < n; i ++) {
            ret = max(ret, dp_buy[i]+dp_sell[i]);
        }
        return ret;
    }

    int maxProfit1(vector<int>& prices) {
        int states[2][4] = {INT_MIN, 0, INT_MIN, 0};
        /*
        states[][0]: one buy
        states[][1]: one buy, one sell
        states[][2]: two buys, one sell
        states[][3]: two buys, two sells
        */
        int n = prices.size();
        int cur = 0, next = 1;
        for(int i = 0; i < n; i ++) {
            states[next][0] = max(states[cur][0], -prices[i]);
            states[next][1] = max(states[cur][1], states[cur][0] + prices[i]);
            states[next][2] = max(states[cur][2], states[cur][1] - prices[i]);
            states[next][3] = max(states[cur][3], states[cur][2] + prices[i]);
            swap(cur, next);
        }
        return max(states[cur][1], states[cur][3]);
    }

};


int main() {
    Solution so;
    int data[] = {1,2};
    vector<int> v(data,data+2);
    cout<<so.maxProfit(v)<<endl;

    return 0;
}