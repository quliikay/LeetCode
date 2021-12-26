/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> flag;
        flag.insert(n);
        while (n != 1) {
            int total = 0;
            while (n != 0) {
                total += pow(n % 10, 2);
                n /= 10;
            }
            n = total;
            if (flag.find(n) != flag.end())
                return false;
            flag.insert(n);
        }
        return true;
    }
};
// @lc code=end
