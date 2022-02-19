/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        int prediff = 0;
        int curdiff = 0;
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            curdiff = nums[i] - nums[i - 1];
            if (curdiff > 0 && prediff <= 0 || curdiff < 0 && prediff >= 0) {
                res++;
                prediff = curdiff;
            }
        }
        return res;
    }
};
// @lc code=end
