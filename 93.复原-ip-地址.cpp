/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12)
            return ans;
        backtracking(s, 0, 0);
        return ans;
    }
    void backtracking(string s, int startIndex, int pointNum) {
        if (pointNum == 3) {
            if (isValid(s, startIndex, s.size() - 1))
                ans.emplace_back(s);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isValid(s, startIndex, i)) {
                s.insert(s.begin() + i + 1, '.');
                backtracking(s, i + 2, pointNum + 1);
                s.erase(s.begin() + i + 1);
            } else
                break;
        }
    }
    bool isValid(string s, int left, int right) {
        if (left > right)
            return false;
        if (s[left] == '0' && left != right)
            return false;
        int num = 0;
        for (int i = left; i <= right; i++) {
            if (s[i] > '9' || s[i] < '0')
                return false;
            num = num * 10 + (s[i] - '0');
        }
        if (num > 255)
            return false;
        return true;
    }
};
// @lc code=end
