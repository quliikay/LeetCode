/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return ans;
    }
    void backtracking(vector<int> nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            ans.emplace_back(path);
            return;
        }
        for (int i = 0; i < used.size(); i++) {
            if (used[i] == true)
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && used[i-1]==false)
                continue;
            used[i] = true;
            path.emplace_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
};
// @lc code=end
