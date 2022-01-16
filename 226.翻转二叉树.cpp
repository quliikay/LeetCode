/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> stk;
        if (root)
            stk.emplace(root);
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            if (cur) {
                if (cur->right)
                    stk.emplace(cur->right);
                if (cur->left)
                    stk.emplace(cur->left);
                stk.emplace(cur);
                stk.emplace(nullptr);
            } else {
                cur = stk.top();
                stk.pop();
                swap(cur->left, cur->right);
            }
        }
        return root;
    }
};
// @lc code=end
