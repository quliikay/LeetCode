/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        unordered_map<char, int> mp;
        for (char a : s)
            mp[a]++;
        for (auto a : mp) {
            int count = a.second;
            ans += count / 2 * 2;
            if (ans % 2 == 0 && count % 2 == 1)
                ans++;
        }
        return ans;
    }
};
// @lc code=end
