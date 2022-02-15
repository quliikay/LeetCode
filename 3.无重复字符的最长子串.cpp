/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1)
            return s.length();
        int left = 0;
        int right = 1;
        int len = 1;
        int res = 1;
        unordered_map<char, int> map;
        map[s[0]] = 1;
        while (right < s.length()) {
            map[s[right]]++;
            len++;
            while (map[s[right]] > 1) {
                len--;
                map[s[left]]--;
                left++;
            }
            right++;
            res = res < len ? len : res;
        }
        return res;
    }
};
// @lc code=end
