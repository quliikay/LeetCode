/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return ans;
    }
    void backtracking(int k, int n, int startIndex) {
        if (path.size() == k && n == 0) {
            ans.emplace_back(path);
            return;
        }
        if (n < 0)
            return;
        for (int i = startIndex; i <= 9; i++) {
            path.emplace_back(i);
            backtracking(k, n - i, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end
