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
        vector<vector<string>> res;
        unordered_map<string, vector<string>> record;
        for (string str : strs) {
            int temp_record[26] = {0};
            string a = "";
            for (char temp : str)
                temp_record[temp - 'a']++;
            for (int i = 0; i < 26; i++) {
                if (temp_record[i] != 0) {
                    a += i + 'a';
                    a += to_string(temp_record[i]);
                }
            }
            record[a].emplace_back(str);
        }
        for (auto a : record)
            res.emplace_back(a.second);
        return res;
    }
};
// @lc code=end
