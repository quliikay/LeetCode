/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--)
            swap(s[i], s[j]);
    };
    void removeExtraSpaces(string& s) {
        int slowIndex = 0, fastIndex = 0;
        while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ')
            fastIndex++;
        for (; fastIndex < s.size(); fastIndex++) {
            if (s[fastIndex] == ' ' && s[fastIndex - 1] == ' ' && fastIndex - 1 >= 0)
                continue;
            else
                s[slowIndex++] = s[fastIndex];
        }
        if (slowIndex - 1 >= 0 && s[slowIndex - 1] == ' ')
            s.resize(slowIndex - 1);
        else
            s.resize(slowIndex);
    }
    string reverseWords(string s) {
        reverse(s, 0, s.size() - 1);
        removeExtraSpaces(s);
        int start = 0, end = 0;
        do {
            while (s[end + 1] != ' '&&end+1<s.size())
                end++;
            reverse(s, start, end);
            start = end + 2;
            end = start;
        } while (start < s.size());
        return s;
    }
};
// @lc code=end
