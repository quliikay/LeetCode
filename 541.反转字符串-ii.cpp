/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        int left = 0;
        while (left + 2 * k <= s.size()) {
            int right = left + k - 1;
            for (int i = left, j = right; i < j; i++, j--)
                swap(s[i], s[j]);
            left += 2 * k;
        }
        if (s.size() - left == 0)
            return s;
        else if (s.size() - left < k) {
            for (int i = left, j = s.size() - 1; i < j; i++, j--)
                swap(s[i], s[j]);
        } else {
            int right = left + k - 1;
            for (int i = left, j = right; i < j; i++, j--)
                swap(s[i], s[j]);
        }
        return s;
    }
};
// @lc code=end
