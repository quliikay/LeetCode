/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int count = cost.size();
        vector<int> dp(count);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2;i<count;i++){
            dp[i] = min(dp[i-1], dp[i-2])+cost[i];
        }
        return min(dp[count-1], dp[count-2]);
    }
};
// @lc code=end

