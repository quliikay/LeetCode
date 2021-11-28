/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT32_MAX;
        int slowIndex = 0;
        int sum = 0;
        int sublength;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            sum += nums[fastIndex];
            while (sum >= target) {
                sublength = fastIndex - slowIndex + 1;
                if (res > sublength)
                    res = sublength;
                sum -= nums[slowIndex++];
            }
        }
        return res == INT32_MAX ? 0 : res;
    }
};
// @lc code=end
