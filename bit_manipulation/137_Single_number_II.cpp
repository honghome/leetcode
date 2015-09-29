// Source : https://leetcode.com/problems/single-number-ii/
// Author : Peiyang Hong
// Date   : 2015-09-19
// stars  : 4
/********************************************************************************** 

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

solution:
1）可以用一个32位的数组来记录每个位置出现的次数，然后求出那写不是3的倍数的位置，最后将这些位再组成一个数

2）用三个变量来记录各个位置出现的次数，

如何记录只出现一次的位，并且把出现过两次的情况：
    one ^= nums[i] 

如何记录出现过两次的位：把出现过两次的保存起来，把从一次变为两次的保存起来
    two |= one & nums[i];

最后，当出现过三次的时候，将其他两个位置清零
    two &= ~three;
    one &= ~three;

**********************************************************************************/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one=0, two=0, three=0;
        int n = nums.size();
        for (int i = 0; i < n ;i ++) {
            two |= one & nums[i];
            one ^= nums[i];
            three = two & one;
            
            two &= ~three;
            one &= ~three;
        }
        return one;
    }
};