/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sCount(26), pCount(26);
        vector<int> ans;
        int slowIndex = 0, fastIndex = 0;
        if (s.length() < p.length())
            return ans;
        for (; fastIndex < p.length(); fastIndex++) {
            pCount[p[fastIndex] - 'a']++;
            sCount[s[fastIndex] - 'a']++;
        }
        if (sCount == pCount)
            ans.emplace_back(0);
        while (fastIndex < s.length()) {
            sCount[s[slowIndex++] - 'a']--;
            sCount[s[fastIndex++] - 'a']++;
            if (pCount == sCount)
                ans.emplace_back(slowIndex);
        }
        return ans;
    }
};
// @lc code=end
