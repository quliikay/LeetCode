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
        unordered_map<char, int> S;
        string::iterator ite;
        for (ite = magazine.begin(); ite != magazine.end(); ite++)
            S[*ite]++;
        for (int i = 0; i < ransomNote.size(); i++) {
            if (--S[ransomNote[i]] < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
