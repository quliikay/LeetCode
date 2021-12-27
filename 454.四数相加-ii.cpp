/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> record;
        for (int i : nums1) {
            for (int j : nums2)
                record[i + j]++;
        }
        int ans = 0;
        for (int i : nums3) {
            for (int j : nums4) {
                int sum = i + j;
                if (record.find(-sum) != record.end())
                    ans+=record.find(-sum)->second;
            }
        }
        return ans;
    }
};
// @lc code=end
