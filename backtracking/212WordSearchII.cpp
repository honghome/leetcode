// Source : https://leetcode.com/problems/word-search-ii/
// Author : Peiyang Hong
// Date   : 2015-10-07
// start  : 

/********************************************************************************** 
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.

click to show hint.

You would need to optimize your backtracking to pass the larger test. 
Could you stop backtracking earlier?

If the current candidate does not exist in all words' prefix, 
you could stop backtracking immediately. 
What kind of data structure could answer such query efficiently? 
Does a hash table work? Why or why not? How about a Trie? 
If you would like to learn how to implement a basic trie, 
please work on this problem: Implement Trie (Prefix Tree) first.
**********************************************************************************/

#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;


class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode():isWord(false) {}
    unordered_map<char, TrieNode*> childs;
    bool isWord;
    string word;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node->childs.find(word[i]) == node->childs.end()) {
                node->childs[word[i]] = new TrieNode();
            }
            node = node->childs[word[i]];
        }
        node->isWord = true;
        node->word = word;
    }

public:
    TrieNode* root;
};


int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void findWords(vector<vector<char> >& board,
               TrieNode* root,
               int x,
               int y,
               vector<string>& ret) {


    if (root && root->isWord) {
        ret.push_back(root->word);
        root->isWord = false;
        return;
    }

    if (x < 0 || y < 0 || 
        x >= board.size() || 
        y >= board[x].size() ||
        board[x][y] == '\0') {
        return ;
    }

    char ch = board[x][y];
    unordered_map<char, TrieNode*>::iterator it = root->childs.find(ch);
    if (it != root->childs.end()) {
        board[x][y] = '\0';
        for (int i = 0; i < 4; i++) {
            findWords(board, it->second, x+dir[i][0], y+dir[i][1], ret);
        }
        board[x][y] = ch;
    }
}
vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
    Trie* trie = new Trie();
    for (int i = 0; i < words.size(); i++) {
        trie->insert(words[i]);
    }
    vector<string> ret;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            findWords(board, trie->root, i, j, ret);
        }
    }
    delete trie;
    return ret;
}

void print_vector(vector<string> v) {
    cout<<"vecotr: "<<endl;
    for (int i = 0; i < v.size(); i++) {
        cout<<v[i]<<endl;
    }
}

int main() {
    int m, n, q;
    vector<string> ret;
    while (cin>>m>>n) {
        string *str = new string[m];
        for (int i = 0; i < m; i++) {
            cin>>str[i];
        }
        cin>>q;
        string *words = new string[q];
        for (int i = 0; i < q; i++) {
            cin>>words[i];
        }
        vector<vector<char> > board;
        for (int i = 0; i < m; i++) {
            vector<char> v(str[i].begin(), str[i].end());
            board.push_back(v);
        }
        vector<string> words_v(words, words+q);
        ret = findWords(board, words_v);
        print_vector(ret);
    }
}

/*
4 4
oaan
etae
ihkr
iflv
4
oath
pea
eat
rain
*/
