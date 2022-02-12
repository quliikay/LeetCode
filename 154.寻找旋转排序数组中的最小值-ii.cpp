/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int right = nums.size() - 1;
        int left = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if(left==right)
                return nums[right];
            if (nums[mid] < nums[right])
                right = mid;
            else if(nums[mid] > nums[right])
                left = mid + 1;
            else right--;
        }
        return -1;
    }
};
// @lc code=end
