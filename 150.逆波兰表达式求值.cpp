/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto i : tokens) {
            if (i == "+" || i == "-" || i == "*" || i == "/") {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                if (i == "+")
                    stk.push(num2 + num1);
                else if (i == "-")
                    stk.push(num2 - num1);
                else if (i == "*")
                    stk.push(num2 * num1);
                else if (i == "/")
                    stk.push(num2 / num1);
            } else
                stk.push(stoi(i));
        }
        int res = stk.top();
        return res;
    }
};
// @lc code=end
