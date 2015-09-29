// Source : https://leetcode.com/problems/single-number-iii/
// Author : Peiyang Hong
// Date   : 2015-09-19
// stars  : 4
/********************************************************************************** 

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?


如果将所有的数做亦或运算的话，我们最终得到这两个不同数的亦或值
接下来就是想办法把它们分开来，由于两个数不同，所以至少存在一个不同的位
我们将最小的一个不同的位找出来，即找到第一个bit 1
然后按照这个bit 1的位置，将数组分成两类，此时会将 a b分在不同的组，并且每个组的其他成员由于都是成对出现的，所以。。。
**********************************************************************************/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        int ret = 0;
        for(int i = 0; i < nums.size(); i++) {
            ret ^= nums[i];
        }
        //find the last diff bit, that is to find the last bit 1
        int cmp = ret&(ret-1)^ret;
        for(int i = 0; i < nums.size(); i++) {
            if (cmp & nums[i]) {
                a ^= nums[i];
            } else {
                b ^= nums[i];
            }
        }
        return vector<int>{a,b};
    }
};