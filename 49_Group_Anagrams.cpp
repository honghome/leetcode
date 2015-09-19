// Source : https://leetcode.com/problems/anagrams/
// Author : Peiyang Hong
// Date   : 2015-09-10

/********************************************************************************** 

Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]


用map存，key 为字符串的radix值，如abaf = a2b1f1, value为相同radix值的字符串

要求每组的字符串要按字母序，于是需要事先排序
**********************************************************************************/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs){
    	sort(strs.begin(), strs.end());

    	map<string, vector<string> > retMap;
    	vector<vector<string> > ret;
    	
    	for (int i = 0; i < strs.size(); i ++) {
    		int count[26] = {0};
    		string key = "";
    		for (int j = 0; j < strs[i].length(); j++)
    			count[strs[i][j] - 'a'] ++;
    		for (int j = 0; j < 26; j ++) {
    			if (count[j]) {
    				key += (j+'a');
    				key += (count[j] +'0');
    			}
    		}
    		map<string, vector<string> >::iterator it = retMap.find(key);
    		if (it == retMap.end()) {
    			vector<string> value;
    			value.push_back(strs[i]);
    			retMap[key] = value;
    		} else {
    			(it->second).push_back(strs[i]);
    		}
    	}
    	map<string, vector<string> >::iterator it = retMap.begin();
    	while(it != retMap.end()) {
    		ret.push_back(it->second);
    		it ++;
    	}
    	return ret;
    }
};