/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int index = 1;
        int left = 0, right = n - 1, up = 0, down = n - 1;
        while (index <= n * n) {
            for (int i = left; i <= right; i++)
                res[up][i] = index++;
            up++;
            for (int i = up; i <= down; i++)
                res[i][right] = index++;
            right--;
            for (int i = right; i >= left; i--)
                res[down][i] = index++;
            down--;
            for (int i = down; i >= up; i--)
                res[i][left] = index++;
            left++;
        }
        return res;
    }
};
// @lc code=end
