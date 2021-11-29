/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (right + left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] == target)
                return mid;
            else
                right = mid - 1;
        }
        return -1;
    }
};
// @lc code=end
