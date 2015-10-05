// Source : https://leetcode.com/problems/word-break-ii/
// Author : Peiyang Hong
// Date   : 2015-10-04

/********************************************************************************** 
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

//---------------------
// Dynamic Programming
//---------------------
//
//  Define substring[i, j] is the sub string from i to j.
//
//       (substring[i,j] == word) :   result[i] = substring[i,j] + {result[j]}
//
//      So, it's better to evaluate it backword. 
//
//  For example:
//
//    s = "catsanddog",
//    dict = ["cat", "cats", "and", "sand", "dog"].
//  
//       0  c  "cat"  -- word[0,2] + {result[3]}  ==> "cat sand dog"
//             "cats" -- word[0,3] + {result[4]}  ==> "cats and dog" 
//       1  a  ""
//       2  t  ""
//       3  s  "sand" --  word[3,6] + {result[7]} ==> "sand dog"
//       4  a  "and"  --  word[4,6] + {result[7]} ==> "and dog"
//       5  n  ""
//       6  d  ""
//       7  d  "dog"
//       8  o  ""
//       9  g  ""

**********************************************************************************/

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    void get_dp(string s, unordered_set<string>& wordDict, bool dp[]) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (wordDict.find(s.substr(0, i+1)) != wordDict.end()) {
                dp[i] = true;
                continue;
            }
            dp[i] = false;
            for (int j = i; j > 0; j--) {
                if (dp[j-1] && wordDict.find(s.substr(j, i-j+1)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> ret;
        int n = s.length();
        if (!n) return ret;
        bool dp[n];
        get_dp(s, wordDict, dp);
        // get TLE when delete this statement
        // so the test data is ....
        if (!dp[n-1]) return ret;
        vector<int> true_ind;
        for (int i = 0; i < n; i++) {
            if (dp[i]) true_ind.push_back(i);
        }
        vector<string> print_str;
        string tmp_str;
        for (int i = 0; i < true_ind.size(); i++) {
            tmp_str = s.substr(0, true_ind[i]+1);
            if (wordDict.find(tmp_str) != wordDict.end()) {
                print_str.push_back(tmp_str);
                get_sentence(s, wordDict, true_ind, i+1, print_str, ret);
                print_str.pop_back();
            }
        }
        return ret;
    }

    void get_sentence(string& ori_str,
                      unordered_set<string>& wordDict,
                      vector<int>& true_ind,
                      int ind,
                      vector<string>& print_str,
                      vector<string>& ret) {
        // get one result
        if (ind == true_ind.size()) {
            string str = "";
            for (int i = 0; i < print_str.size(); i++) {
                str += (print_str[i] + " ");
            }
            ret.push_back(str.substr(0, str.length()-1));
        }

        for (int i = ind; i < true_ind.size(); i++) {
            string tmp_str = ori_str.substr(true_ind[ind-1]+1, true_ind[i]-true_ind[ind-1]);
            //cout<<i<<" "<<tmp_str<<endl;
            if (wordDict.find(tmp_str) != wordDict.end()) {
                print_str.push_back(tmp_str);
                get_sentence(ori_str, wordDict, true_ind, i+1, print_str, ret);
                print_str.pop_back();
            }
        }
    }
};


// 状态压缩
class Solution1 {
public:
    public:
    void get_dp(string s, unordered_set<string>& wordDict, bool dp[]) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (wordDict.find(s.substr(0, i+1)) != wordDict.end()) {
                dp[i] = true;
                continue;
            }
            dp[i] = false;
            for (int j = i; j > 0; j--) {
                if (dp[j-1] && wordDict.find(s.substr(j, i-j+1)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> ret_null;
        int n = s.length();
        if (!n) return ret_null;
        
        bool dp[n];
        get_dp(s, wordDict, dp);
        if (!dp[n-1]) return ret_null;
        
        vector<int> true_ind;
        true_ind.push_back(-1);
        for (int i = 0; i < n; i++) {
            if (dp[i]) true_ind.push_back(i);
        }

        vector<vector<string> > ret(true_ind.size()-1);
        for (int i = true_ind.size()-2; i >= 0 ; i--) {
            int start_id = true_ind[i] + 1;
            vector<string> v;
            ret[i] = v;
            for (int j = i+1; j < true_ind.size(); j++) {
                int len = true_ind[j] - true_ind[i];
                string tmp_str = s.substr(start_id, len);
                if (wordDict.find(tmp_str) != wordDict.end()) {
                    if (j == true_ind.size() - 1) {
                        ret[i].push_back(tmp_str);
                    } else {
                        for (int k = 0; k < ret[j].size(); k++) {
                            ret[i].push_back(tmp_str + " " + ret[j][k]);
                        }
                    }
                }
            }
        }
        return ret[0];
    }
};

void print_vector(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        cout<<v[i]<<endl;
    }
}

int main() {
    Solution1 so;
    string s = "catsanddog";
    string data[] = {"cat", "cats", "and", "sand", "dog"};
    unordered_set<string> dict;
    dict.insert(data, data+5);
    vector<string> ret = so.wordBreak(s, dict);
    print_vector(ret);


    return 0;
}














