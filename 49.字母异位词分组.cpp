/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int num = strs.size();
        unordered_map<string, vector<string>> res;
        for (string a : strs) {
            string key = a;
            sort(key.begin(), key.end());
            res[key].emplace_back(a);
        }
        vector<vector<string>> ans;
        unordered_map<string, vector<string>>::iterator ite;
        for (ite = res.begin(); ite != res.end(); ite++)
            ans.emplace_back(ite->second);
        return ans;
    }
};
// @lc code=end
