/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1, map2;
        vector<int> ans;
        for (int i : nums1)
            map1[i]++;
        for (int i : nums2)
            map2[i]++;
        for (auto i : map1) {
            if (map2.find(i.first) != map2.end()) {
                int num = i.second < map2.find(i.first)->second ? i.second : map2.find(i.first)->second;
                while(num--){
                    ans.emplace_back(i.first);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
