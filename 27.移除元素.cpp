/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0, fastIndex = 0;
        for(;fastIndex<nums.size();fastIndex++){
            if(nums[fastIndex]!=val)
                nums[slowIndex++] = nums[fastIndex];
        }
        return slowIndex;
    }
};
// @lc code=end
