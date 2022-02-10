/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = i; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    if (j == i)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                }else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][nums.size()-1];
    }
};
// @lc code=end
