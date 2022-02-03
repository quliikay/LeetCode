/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return ans;
    }
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            ans.emplace_back(path);
            return;
        }
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
            path.emplace_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end
