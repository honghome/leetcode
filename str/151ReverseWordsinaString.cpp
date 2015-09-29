// Source : https://leetcode.com/problems/reverse-words-in-a-string/
// Author : Peiyang Hong
// Date   : 2015-09-29

/********************************************************************************** 
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

算法：
倒着扫描字符串，遇到一个连续的字符串，就把他放到结果里面，最后将结果放回原字符串
注意：
	在对结果字符串删除最后一个空格的时候，需要事先判断结果字符串是否为空

**********************************************************************************/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
    	string tmp_str = s;
    	string new_str = "";
    	int i = tmp_str.length() -  1;
    	int start_id, end_id;
    	while (i >= 0) {
    		//clear the space
    		while (i >= 0 && tmp_str[i] == ' ') {
    			i --;
    		}
    		if (i < 0) {
    			break;
    		}
    		//get the 
    		end_id = i;
    		while (i >=0 && tmp_str[i] != ' ') {
    			i --;
    		}
    		start_id = i + 1;
    		// fill the ret
    		for (int j = start_id; j <= end_id; j++) {
    			new_str += tmp_str[j];
    		}
    		new_str += ' ';
    	}
    	// delete the last space
    	if (new_str.length() > 0) {
    		new_str.erase(new_str.end() - 1);
    	}
    	s = new_str;
    }
};