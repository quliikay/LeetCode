/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> rest(gas.size(), 0);
        for (int i = 0; i < gas.size(); i++)
            rest[i] = gas[i] - cost[i];
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < rest.size(); i++) {
            curSum += rest[i];
            totalSum += rest[i];
            if (curSum < 0) {
                curSum = 0;
                start = i + 1;
            }
        }
        if (totalSum < 0)
            start = -1;
        return start;
    }
};
// @lc code=end
