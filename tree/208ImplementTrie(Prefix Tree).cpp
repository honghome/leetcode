// Source : https://leetcode.com/problems/word-search/
// Author : Peiyang Hong
// Date   : 2015-10-06
// start  : 
/********************************************************************************** 
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.

**********************************************************************************/

#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;


class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode():cnt(0) {}
    unordered_map<char, TrieNode*> childs;
    int cnt;
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
        node->cnt++;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        return retrieve(word, true);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return retrieve(prefix, false);
    }

private:
    TrieNode* root;

    inline bool retrieve(const string& key, bool isWord) {
        if (key.size() <= 0) return false;
        TrieNode* node = root;
        for (int i = 0; i < key.length(); i++) {
            if (node->childs.find(key[i]) == node->childs.end())
                return false;
            node = node->childs[key[i]];
        }
        return isWord ? node->cnt : true;
    }
};

int main() {
    int q;
    string str;
    Trie trie;
    while (cin>>q>>str) {
        //q:command type, 1 insert, 2 search, 3 startwith
        //str: content
        if (q == 1) {
            trie.insert(str);
        } else if (q == 2) {
            cout<<"result "<<trie.search(str)<<endl;
        } else {
            cout<<"result "<<trie.startsWith(str)<<endl;
        }
    }
}
// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");