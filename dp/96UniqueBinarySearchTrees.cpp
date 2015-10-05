// Source : https://leetcode.com/problems/unique-binary-search-trees/
// Author : Peiyang Hong
// Date   : 2015-10-05

/********************************************************************************** 
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

   
**********************************************************************************/



/*
0 1
1 1
2 2
3 (0,2) (2,0) (1,1) 5
4 (0,3) (3,0) (2,1) (1,2) 14
5 (0,4) (4,0) (1,3) (3,1) (2,2) 14*2+5*2+2*2 = 42
6 (0,5) (5,0) (1,4) (4,1) (2,3) (3,2) 2(42+14+10) 

*/

#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int a[5] = {1,1,2,5,14};
        for (int i = 5; i <= n; i++) {
            a[i] = 0;
            for (int j = 0; j <= (i-1)/2; j++) {
                int k = i - j - 1;
                a[i] += a[j]*a[k];
            }
            a[i] *= 2;
            if (i % 2) a[i] -=a[i/2]*a[i/2];
        }
        return a[n];
    }
};

int main() {
	Solution so;
	int a;
	while(cin>>a) {
		cout<<so.numTrees(a)<<endl;
	}
    return 0;
}


