// Source : https://leetcode.com/problems/surrounded-regions/
// Author : Peiyang Hong
// Date   : 2015-09-29

/********************************************************************************** 
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

用dfs爆栈
用bfs通过，从四条边遍历所有'O'自字符，然后对遍历不到的'O'字符变成'X'字符

**********************************************************************************/

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char> >& board) {
        int m, n;

        m = board.size();
        if (m == 0) {
            return ;
        }
        n = board[0].size();
        if (n == 0) {
            return ;
        }
        //cout<<m<<" "<<n<<endl;
        bool **visited = new bool* [m];
        for (int i = 0; i < m; i++) {
        	visited[i] = new bool[n];
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < m; i++) {
        	if (!visited[i][0] && board[i][0] == 'O') {
        		surrounded(board, visited, m, n, i, 0);
        	}
        	if (!visited[i][n-1] && board[i][n-1] == 'O') {
        		surrounded(board, visited, m, n, i, n-1);
        	}
        }
        for (int j = 0; j < n; j++) {
        	if (!visited[0][j] && board[0][j] == 'O') {
        		surrounded(board, visited, m, n, 0, j);
        	}
        	if (!visited[m-1][j] && board[m-1][j] == 'O') {
        		surrounded(board, visited, m, n, m-1,j);
        	}
        }
        for (int i = 1; i < m - 1; i++) {
        	for (int j = 1; j < n - 1; j++) {
        		if (!visited[i][j] && board[i][j] == 'O') {
        			board[i][j] = 'X';     
        		}
        	}
        }
    }
    /*
    // dfs run time error
    void surrounded(vector<vector<char> >& board, bool **visited, int m, int n, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
        	return;
        }
        //cout<<"<<"<<i<<" "<<j<<endl;
        if (!visited[i][j] && board[i][j] == 'O') {
            visited[i][j] = true;
            surrounded(board, visited, m, n, i + 1, j);
            surrounded(board, visited, m, n, i - 1, j);
            surrounded(board, visited, m, n, i, j + 1);
            surrounded(board, visited, m, n, i, j - 1);
        }
    }*/
    // bfs
    void surrounded(vector<vector<char> >& board, bool **visited, int m, int n, int r, int c) {
    	pair<int, int> tmp_elem(r,c);
    	queue<pair<int, int> > que;
    	int i,j;
    	int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    	que.push(tmp_elem);
    	visited[r][c] = true;
    	while (!que.empty()) {
    		pair<int, int> cur_elem = que.front();
    		que.pop();
    		for (int k = 0; k < 4; k++) {
    			i = cur_elem.first + dir[k][0];
    			j = cur_elem.second + dir[k][1];
    			if (i >= 0 && i < m && j >=0 && j < n && !visited[i][j]) {
    				visited[i][j] = true;
    				if (board[i][j] == 'O') {
    					tmp_elem.first = i;
    					tmp_elem.second = j;
    					que.push(tmp_elem);
    				}
    			}
    		}
    	}
    }
};