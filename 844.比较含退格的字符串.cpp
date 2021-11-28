/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1;
        int skipS = 0, skipT = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#')
                    skipS++, i--;
                else if (skipS > 0)
                    skipS--, i--;
                else
                    break;
            }
            while (j >= 0) {
                if (t[j] == '#')
                    skipT++, j--;
                else if (skipT > 0)
                    skipT--, j--;
                else
                    break;
            }
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j])
                    return false;
            } else if (i >= 0 || j >= 0)
                return false;
            i--, j--;
        }
        return true;
    }
};
// @lc code=end
