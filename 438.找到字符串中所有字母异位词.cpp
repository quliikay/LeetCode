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
        int pLen = p.size();
        int sLen = s.size();
        if (sLen < pLen)
            return vector<int>();
        vector<int> pCount(26);
        vector<int> sCount(26);
        int slowIndex = 0, fastIndex = 0;
        vector<int> ans;
        for (fastIndex = 0; fastIndex < pLen; fastIndex++) {
            pCount[p[fastIndex] - 'a']++;
            sCount[s[fastIndex] - 'a']++;
        }
        if (pCount == sCount)
            ans.emplace_back(0);
        while (fastIndex < sLen) {
            sCount[s[fastIndex++] - 'a']++;
            sCount[s[slowIndex++] - 'a']--;
            if (pCount == sCount)
                ans.emplace_back(slowIndex);
        }
        return ans;
    }
};
// @lc code=end
