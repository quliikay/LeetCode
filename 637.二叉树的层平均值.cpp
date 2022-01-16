/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}

    class Solution {
    public:
        vector<double> averageOfLevels(TreeNode* root) {
            vector<double> res;
            queue<TreeNode*> que;
            if (root)
                que.emplace(root);
            while (!que.empty()) {
                int size = que.size();
                double sum = 0;
                for (int i = 0; i < size; i++) {
                    TreeNode* cur = que.front();
                    sum += cur->val;
                    que.pop();
                    if (cur->left)
                        que.emplace(cur->left);
                    if (cur->right)
                        que.emplace(cur->right);
                }
                res.emplace_back(sum/size);
            }
            return res;
        }
    };
    // @lc code=end
