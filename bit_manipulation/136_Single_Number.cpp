// Source : https://leetcode.com/problems/single-number/
// Author : Peiyang Hong
// Date   : 2015-09-19
// stars  : 3
/********************************************************************************** 

Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

solution:
采用亦或运算，相同的两个数亦或之后为0，再加上一个不同的数，将所有的数亦或之后，最后得到的数就是一个只出现一次的数

**********************************************************************************/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int ret = nums[0];
        for(int i = 1; i < nums.size(); i ++) {
            ret ^= nums[i];
        }
        return ret;
    }
};