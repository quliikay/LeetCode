/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == nums[right])
                return nums[mid];
            else if (nums[mid] < nums[right])
                right = mid;
            else
                left = mid + 1;
        }
        return -1;
    }
};
// @lc code=end
