/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                return ans;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int right = nums.size() - 1;
            int left = i + 1;
            while (left < right) {
                if (nums[left] + nums[right] + nums[i] > 0)
                    right--;
                else if (nums[left] + nums[right] + nums[i] < 0)
                    left++;
                else {
                    ans.emplace_back(vector<int>{nums[i], nums[right], nums[left]});
                    while (right > left && nums[right] == nums[right - 1])
                        right--;
                    while (right > left && nums[left] == nums[left + 1])
                        left++;
                    right--;
                    left++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end