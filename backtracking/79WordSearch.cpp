// Source : https://leetcode.com/problems/word-search/
// Author : Peiyang Hong
// Date   : 2015-10-06
// start  : 4
/********************************************************************************** 
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

algorithm:
	看discuss里面的讨论，是按顺序搜索每一个word，而不是按任意顺序，于是算法就变成了简单的dfs
**********************************************************************************/

#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

#define GET_INDEX(ch) (('a'<=ch && ch <='z')?(ch-'a'):(ch-'A'+26));

bool dfs(vector<vector<char> >& board,
		 vector<vector<bool> >& visit,
		 string& word,
		 int id,
		 int x,
		 int y) {
	if (id == word.length()) return true;
	int m = board.size();
	int n = board[0].size();
	if (x >= 0 && x < m && y >= 0 && y < n && 
		!visit[x][y] &&
		word[id]== board[x][y]) {
		visit[x][y] = true;
		for (int i = 0; i < 4; i++) {
			if (dfs(board, visit, word, id+1, x+dir[i][0], y+dir[i][1]))
				return true;
		}
		visit[x][y] = false;
	}
	return false;
}

bool exist(vector<vector<char> >& board, string word) {
	int m = board.size();
	if (!m) return false;
	int n = board[0].size();
	vector<bool> v(n, false);
	vector<vector<bool> > visit(m, v);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (dfs(board, visit, word, 0, i, j))
				return true;
		}
	}
	return false;
}

int main() {
	int m, n;
	while (cin>>m>>n) {
		string *str = new string[m];
		string match;
		for (int i = 0; i < m; i++)
			cin>>str[i];
		cin>>match;
		vector<vector<char> > board;
		for (int i = 0; i < m; i++) {
			vector<char> v(str[i].begin(), str[i].end());
			board.push_back(v);
		}
		cout<<exist(board, match);
	}
}


/*
ABCE
SFCS
ADEE

ABCCED
*/