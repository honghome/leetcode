// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Author : Peiyang Hong
// Date   : 2015-09-18

/********************************************************************************** 
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

可以多次交易，但是卖之前一定要买

思路1
就是求每一个股票价格上升区间的差的和, 算法的思路就是求每一个上升空间

思路2
其实只要求相邻两个元素中，是上升的空间就可以了

**********************************************************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy_time = 1; // ind of the array prices
        int profit = 0;
        while(buy_time < n) {
            while(buy_time < n && prices[buy_time] <= prices[buy_time-1]) {
            	buy_time ++;
            }
            if (buy_time >= n) {
            	break;
            }
            int sell_time = buy_time;
            buy_time --;
            while (sell_time < n && prices[sell_time] >= prices[sell_time-1]) {
            	sell_time ++;
            }
            sell_time --;
            profit += prices[sell_time] - prices[buy_time];
            if (sell_time == n - 1)
            	break;
            buy_time =  sell_time + 1;
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
    	int profit = 0;
    	for(int i = 1; i < prices.size(); i ++) {
    		if (prices[i] > prices[i-1])
    			profit += prices[i] - prices[i-1];
    	}
    	return profit;
    }
};