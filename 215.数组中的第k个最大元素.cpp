/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void popSort(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        for (int i = right; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[j + 1])
                    swap(nums[j], nums[j + 1]);
            }
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        popSort(nums);
        int res = nums[k - 1];
        return res;
    }
};
// @lc code=end
