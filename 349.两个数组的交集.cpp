/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> nums(nums1.begin(),nums1.end());
        for(int i:nums2){
            if(nums.find(i)!=nums.end())
                result.insert(i);
        }
        return vector<int>(result.begin(),result.end());
    }
};
// @lc code=end
