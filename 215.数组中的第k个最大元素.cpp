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
    void quickSort(int left, int right, vector<int>& nums) {
        if (left >= right)
            return;
        int i = left, j = right, base = nums[left];
        while (i < j) {
            while (i < j && nums[j] <= base)
                j--;
            while (i < j && nums[i] >= base)
                i++;
            if (i < j)
                swap(nums[i], nums[j]);
        }
        nums[left] = nums[i];
        nums[i] = base;
        quickSort(left, i - 1, nums);
        quickSort(i + 1, right, nums);
    }
    int findKthLargest(vector<int>& nums, int k) {
        quickSort(0, nums.size() - 1, nums);
        int res = nums[k - 1];
        return res;
    }
};
// @lc code=end
