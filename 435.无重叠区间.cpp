/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int rightBoundary = intervals[0][1];
        int res = 1;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= rightBoundary) {
                res++;
                rightBoundary = intervals[i][1];
            }
        }
        return intervals.size() - res;
    }
};
// @lc code=end
