// Source : https://leetcode.com/problems/missing-number/
// Author : Peiyang Hong
// Date   : 2015-10-12
// stars  : 
/********************************************************************************** 

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

**********************************************************************************/

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int ret = 0;
    for (int i = 0; i <= n; i++) {
        ret ^= i;
    }
    for (int i = 0; i < n; i++) {
        ret ^= nums[i];
    }
    return ret;
}