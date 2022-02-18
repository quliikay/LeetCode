/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int num = strs[0].length();
        for (auto i : strs)
            num = num < i.length() ? num : i.length();
        string ans = "";
        for (int i = 0; i < num; i++) {
            char cnt = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (cnt != strs[j][i]) {
                    return ans;
                }
            }
            ans += cnt;
        }
        return ans;
    }
};
// @lc code=end
