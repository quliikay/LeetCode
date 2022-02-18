/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const string letterMap[10] = {
        "",      // 0
        "",      // 1
        "abc",   // 2
        "def",   // 3
        "ghi",   // 4
        "jkl",   // 5
        "mno",   // 6
        "pqrs",  // 7
        "tuv",   // 8
        "wxyz",  // 9
    };
    string path;
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return res;
        backtracking(digits, 0);
        return res;
    }
    void backtracking(string digits, int index) {
        if (index == digits.size()) {
            res.emplace_back(path);
            return;
        }
        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for (int i = 0; i < letters.size(); i++) {
            path.push_back(letters[i]);
            backtracking(digits, index + 1);
            path.pop_back();
        }
    }
};
// @lc code=end
