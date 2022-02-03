/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0);
        return res;
    }
    void backtracking(vector<int>& candidates, int target, int startIndex) {
        if (target == 0) {
            res.emplace_back(path);
            return;
        }
        if (target < 0)
            return;
        for (int i = startIndex; i < candidates.size(); i++) {
            path.emplace_back(candidates[i]);
            backtracking(candidates, target - candidates[i], i);
            path.pop_back();
        }
    }
};
// @lc code=end
