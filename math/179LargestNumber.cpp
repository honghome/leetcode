#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

bool cmp(string a, string b)
{
	return a > b;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
    	stringstream ss;
    	vector<string> nums_str;
    	for (int i = 0; i < nums.size(); i++) {
    		ss<<nums[i];
    		nums_str.push_back(ss.str());
    		ss.str("");
    	}
    	string s1 = to_string(11123);
    	cout<<s1<<endl;
    	sort(nums_str.begin(), nums_str.end(), cmp);
    	for (int i = 0; i < nums_str.size(); i++) {
    		cout<<nums_str[i]<<endl;
    	}
    	return "";
    }
};

int main() {
	int data[] = {3, 30, 34, 5, 9};
	vector<int> v(data, data+5);
	Solution so;
	so.largestNumber(v);
	return 0;
}

/*

*/