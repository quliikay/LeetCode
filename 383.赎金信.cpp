/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length())
            return false;
        int record[26] = {0};
        for (char temp : magazine)
            record[temp - 'a']++;
        for (char temp : ransomNote)
            record[temp - 'a']--;
        for (int i : record) {
            if (i < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
