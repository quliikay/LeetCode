/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (char temp : s)
            record[temp - 'a']++;
        for (char temp : t)
            record[temp - 'a']--;
        for (int i : record) {
            if (i != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
