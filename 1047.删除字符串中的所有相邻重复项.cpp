/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for (auto i : s) {
            if (stk.empty())
                stk.push(i);
            else if (stk.top() == i)
                stk.pop();
            else
                stk.push(i);
        }
        string res = "";
        while (!stk.empty()) {
            res+=stk.top();
            stk.pop();
        }
        reverse (res.begin(), res.end());
        return res;
    }
};
// @lc code=end
