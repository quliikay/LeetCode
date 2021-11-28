/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int i = 0;
        int j = nums.size() - 1;
        int pos = j;
        while (i <= j) {
            if (abs(nums[i]) > abs(nums[j]))
                res[pos--] = pow(nums[i++], 2);
            else
                res[pos--] = pow(nums[j--], 2);
        }
        return res;
    }
};
// @lc code=end
