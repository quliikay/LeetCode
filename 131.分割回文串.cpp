/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> path;
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return ans;
    }
    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
    void backtracking(string a, int startIndex) {
        if (startIndex >= a.size()) {
            ans.emplace_back(path);
            return;
        }
        for (int i = startIndex; i < a.size(); i++) {
            if (isPalindrome(a, startIndex, i)) {
                string str = a.substr(startIndex, i - startIndex + 1);
                path.emplace_back(str);
                backtracking(a, i + 1);
                path.pop_back();
            }
        }
    }
};
// @lc code=end
