// Source : https://leetcode.com/problems/integer-to-english-words/
// Author : Peiyang Hong
// Date   : 2015-10-04

/********************************************************************************** 
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"


algorithm:
int类型的组成：x,xxx,xxx,xxx --> billion,million,thousand,xxx

我们只要计算出每个部分的表示方式，再加上各个部分的说法，就可以了

**********************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    string numberToWords(int num) {
    	string ret = "";
    	int digit;

    	digit = num / 1000000000;
    	ret += digit > 0 ? read_three_digit(digit) + "Billion " : "";
    	
    	num %= 1000000000;
    	digit = num / 1000000;
    	ret += digit > 0 ? read_three_digit(digit) + "Million " : "";

    	num %= 1000000;
    	digit = num / 1000;
    	ret += digit > 0 ? read_three_digit(digit) + "Thousand " : "";

    	num %= 1000;
    	digit = num;
    	ret += read_three_digit(digit);

    	if (ret == "")
    		return "Zero";
		return ret.substr(0, ret.length()-1);
    }

    string read_three_digit(int num) {
    	if (num == 0) return "";
    	string ret = "";
    	ret += num >= 100 ? unit[num/100] + "Hundred " : "";
    	num %= 100;
    	int a = num / 10;
    	if (a == 1) {
    		ret += one_ten[num%10];
    	} else {
    		ret += decade[a];
    		ret += unit[num%10];
    	}
    	//cout<<"ret "<<ret<<endl;
    	return ret;
    }

private:
	string unit[20] = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten "};
	string one_ten[20] = {"Ten ", "Eleven ", "Twelve " ,"Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
	string decade[20] = {"", "Ten ", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
};


int main() {
	Solution so;
	int a;
	while(cin>>a) {
		cout<<so.numberToWords(a)<<endl;
	}
}











