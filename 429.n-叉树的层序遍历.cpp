/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
d

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> que;
        if (root)
            que.emplace(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec(size);
            for (int i = 0; i < size; i++) {
                Node* cur = que.front();
                que.pop();
                vec[i] = cur->val;
                vector<Node*> temp = cur->children;
                for (auto i : temp) {
                    if (i)
                        que.emplace(i);
                }
            }
            res.emplace_back(vec);
        }
        return res;
    }
};
// @lc code=end
