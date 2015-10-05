// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author : Peiyang Hong
// Date   : 2015-09-18

/********************************************************************************** 
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.

不买卖，那就是一分钱赚
假设在 j时刻买，那么就在[j+1,end]时刻选择一个最高的价卖掉
于是我们可以从后往前扫面，通过得到j的值和[j+1,end]区间的大小来计算结果
时间复杂度o(n)

**********************************************************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        int buy_time = n - 2;
        int max_price = prices[n-1];
        int max_profit = 0;
        while(buy_time >=0) {
            if (max_profit < max_price - prices[buy_time]) {
                max_profit = max_price - prices[buy_time];
            }
            max_price = max(max_price, prices[buy_time]);
            buy_time --;
        }
        return max_profit;
    }
};