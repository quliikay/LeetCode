/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slowIndex = 0, fastIndex = 0;
        for (; fastIndex < nums.size(); fastIndex++) {
            if (slowIndex == 0 || nums[fastIndex] != nums[slowIndex - 1])
                nums[slowIndex++] = nums[fastIndex];
        }
        return slowIndex;
    }
};
// @lc code=end
