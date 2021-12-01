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
        unordered_map<char, int> S, T;
        int slength = s.length();
        int tlength = t.length();
        if (slength != tlength)
            return false;
        for (int i = 0; i < tlength; i++) {
            S[s[i]]++;
            T[t[i]]++;
        }
        if (S == T)
            return true;
        return false;
    }
};
// @lc code=end
