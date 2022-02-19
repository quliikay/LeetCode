/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<pair<int, int>> start;
    vector<pair<int, int>> path;
    int used[6][6] = {0};
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0])
                    start.emplace_back(pair<int, int>{i, j});
            }
        }
        for(auto i:start){
            path.emplace_back(i);
            used[i.first][i.second] = 1;
            if(backtracking(word, 1, board))
                return true;
            used[i.first][i.second] = 0;
            path.pop_back();
        }
        return false;
    }
    bool backtracking(string word, int cnt, vector<vector<char>>& board) {
        if (cnt == word.size())
            return true;
        int row = path[path.size() - 1].first;
        int col = path[path.size() - 1].second;
        if (row - 1 >= 0 && used[row - 1][col] == 0 && board[row - 1][col] == word[cnt]) {
            path.emplace_back(pair<int, int>{row - 1, col});
            used[row - 1][col] = 1;
            if (backtracking(word, cnt + 1, board))
                return true;
            path.pop_back();
            used[row - 1][col] = 0;
        }
        if (row + 1 < board.size() && used[row + 1][col] == 0 && board[row + 1][col] == word[cnt]) {
            path.emplace_back(pair<int, int>{row + 1, col});
            used[row + 1][col] = 1;
            if (backtracking(word, cnt + 1, board))
                return true;
            path.pop_back();
            used[row + 1][col] = 0;
        }
        if (col - 1 >= 0 && used[row][col - 1] == 0 && board[row][col - 1] == word[cnt]) {
            path.emplace_back(pair<int, int>{row, col - 1});
            used[row][col - 1] = 1;
            if (backtracking(word, cnt + 1, board))
                return true;
            path.pop_back();
            used[row][col - 1] = 0;
        }
        if (col + 1 < board[0].size() && used[row][col + 1] == 0 && board[row][col + 1] == word[cnt]) {
            path.emplace_back(pair<int, int>{row, col + 1});
            used[row][col + 1] = 1;
            if (backtracking(word, cnt + 1, board))
                return true;
            path.pop_back();
            used[row][col + 1] = 0;
        }
        return false;
    }
};
// @lc code=end
