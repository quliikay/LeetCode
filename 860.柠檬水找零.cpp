/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for (int i : bills) {
            if (i == 5)
                five++;
            else if (i == 10) {
                ten++;
                if (five < 1)
                    return false;
                five--;
            } else {
                twenty++;
                if (ten >= 1 && five >= 1) {
                    five--;
                    ten--;
                } else if (five >= 3) {
                    five -= 3;
                } else
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
