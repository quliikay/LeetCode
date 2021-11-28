/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int sum = n * m;
        int left = 0, up = 0, right = n - 1, down = m - 1;
        vector<int> res;
        while (sum > 0) {
            for (int i = left; i <= right && sum > 0; i++) {
                res.push_back(matrix[up][i]);
                sum--;
            }
            up++;
            for (int i = up; i <= down && sum > 0; i++) {
                res.push_back(matrix[i][right]);
                sum--;
            }
            right--;
            for (int i = right; i >= left && sum > 0; i--) {
                res.push_back(matrix[down][i]);
                sum--;
            }
            down--;
            for (int i = down; i >= up && sum > 0; i--) {
                res.push_back(matrix[i][left]);
                sum--;
            }
            left++;
        }
        return res;
    }
};
// @lc code=end
