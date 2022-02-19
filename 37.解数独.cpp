/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
    bool backtracking(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.')
                    continue;
                for (char k = '1'; k <= '9'; k++) {
                    if (isValid(i, j, k, board)) {
                        board[i][j] = k;
                        if (backtracking(board))
                            return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    bool isValid(int row, int col, char val, vector<vector<char>> board) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == val)
                return false;
        }
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == val)
                return false;
        }
        int Xindex = (row / 3) * 3;
        int Yindex = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[Xindex + i][Yindex + j] == val)
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
