/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return ans;
    }
    void backtracking(vector<int>& candidates, int target, int startIndex) {
        if (target == 0) {
            ans.emplace_back(path);
            return;
        }
        if (target < 0)
            return;
        for (int i = startIndex; i < candidates.size(); i++) {
            if(i>startIndex&&candidates[i-1]==candidates[i])
                continue;
            path.emplace_back(candidates[i]);
            backtracking(candidates, target-candidates[i], i+1);
            path.pop_back();
        }
    }
};
// @lc code=end
