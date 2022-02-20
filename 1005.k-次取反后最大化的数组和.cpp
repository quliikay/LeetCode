/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
public:
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int result = 0;
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && k > 0) {
                k--;
                nums[i] *= -1;
            }
        }
        if (k % 2 == 1)
            nums[nums.size() - 1] *= -1;
        for (int a : nums)
            result += a;
        return result;
    }
};
// @lc code=end
