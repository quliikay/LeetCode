/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<char, int> temp, res;
    bool check() {
        for (const auto& p : temp) {
            if (res[p.first] < p.second)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int slowIndex = 0;
        int ansl = 0;
        for (const char& p : t)
            temp[p]++;
        int length = INT32_MAX;
        for (int fastIndex = 0; fastIndex < s.size(); fastIndex++) {
            if (temp.find(s[fastIndex]) != temp.end())
                res[s[fastIndex]]++;
            while (check()) {
                if (length > fastIndex - slowIndex + 1) {
                    length = fastIndex - slowIndex + 1;
                    ansl = slowIndex;
                }
                if (temp.find(s[fastIndex]) != temp.end())
                    res[s[slowIndex]]--;
                slowIndex++;
            }
        }
        return length == INT32_MAX ? string() : s.substr(ansl, length);
    }
};
// @lc code=end
