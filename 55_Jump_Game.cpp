// Source : https://oj.leetcode.com/problems/powx-n/
// Author : Peiyang Hong
// Date   : 2015-09-10

/********************************************************************************** 
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

s1: dp判断 超时
s2: 判断能不能跳过每个nums[i]==0 的地方，注意nums[n-1]==0的情况
**********************************************************************************/

public:
    bool canJump(vector<int>& nums) {
        /* TLE
        int n = nums.size();
        bool dp[n] = {false};
        dp[0] = true;
        for (int j = 1; j < n; j ++) {
            for (int i = j-1; i >= 0; i --) {
                if(dp[i] && j - i <= nums[i]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n-1];
        */
        
        int n = nums.size();
        if (n <= 1) {
            return true;
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i]) {
                continue;
            }
            int j = i - 1;
            for (; j >= 0; j --) {
                if ((i == n -1 && i - j <= nums[j]) || i - j < nums[j]) {
                    // can jump the 0
                    break;
                }
            }
            if (j < 0) {
                return false;
            }
        }
        return true;
    }
};