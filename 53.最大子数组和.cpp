/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        vector<int> dp(nums.size());
        
        dp[0] = nums[0];
        int ans = dp[0];
        for(int i=1;i<nums.size();i++){
            dp[i] = max(nums[i], dp[i-1]+nums[i]);
            ans = ans<dp[i]?dp[i]:ans;
        }
        return ans;
    }
};
// @lc code=end
