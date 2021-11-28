/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int slowIndex = 0;
        int type = 0;
        int x = 0, y = 0;
        int xn = -1, yn = -1;
        int res = 0;
        for (int fastIndex = 0; fastIndex < fruits.size(); fastIndex++) {
            if (fruits[fastIndex] == xn)
                x++;
            else if (fruits[fastIndex] == yn)
                y++;
            else if (x == 0)
                xn = fruits[fastIndex], x++, type++;
            else if (y == 0)
                yn = fruits[fastIndex], y++, type++;
            else {
                // fastIndex是新元素
                type++;
                while (type > 2) {
                    if (xn == fruits[slowIndex]) {
                        x--, slowIndex++;
                        if (x == 0) {
                            xn = fruits[fastIndex];
                            x = 1;
                            type--;
                        }
                    } else {
                        y--, slowIndex++;
                        if (y == 0) {
                            yn = fruits[fastIndex];
                            y = 1;
                            type--;
                        }
                    }
                }
            }
            res = (x + y) > res ? (x + y) : res;
        }
        return res;
    }
};
// @lc code=end
