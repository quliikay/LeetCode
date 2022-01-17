/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
};

class Solution {
public:
    // int sumOfLeftLeaves(TreeNode* root) {
    //     if (!root)
    //         return 0;
    //     int leftValue = sumOfLeftLeaves(root->left);
    //     int rightValue = sumOfLeftLeaves(root->right);
    //     int midValue = 0;
    //     if (root->left && !root->left->left && !root->left->right)
    //         midValue = root->left->val;
    //     return leftValue + rightValue + midValue;
    // }
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> stk;
        int res = 0;
        if (root)
            stk.emplace(root);
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            if (cur) {
                if (cur->left)
                    stk.emplace(cur->left);
                if (cur->right)
                    stk.emplace(cur->right);
                stk.emplace(cur);
                stk.emplace(nullptr);
            } else {
                cur = stk.top();
                stk.pop();
                if (cur->left && !cur->left->left && !cur->left->right) {
                    res += cur->left->val;
                }
            }
        }
        return res;
    }
};
// @lc code=end
