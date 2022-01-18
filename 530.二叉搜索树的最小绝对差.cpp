/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        TreeNode* pre = nullptr;
        stack<TreeNode*> stk;
        if (root)
            stk.emplace(root);
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            if (cur) {
                if (cur->right)
                    stk.push(cur->right);
                stk.push(cur);
                stk.push(nullptr);
                if (cur->left)
                    stk.push(cur->left);
            } else {
                cur = stk.top();
                stk.pop();
                if (pre != nullptr && abs(pre->val - cur->val) < res)
                    res = abs(pre->val - cur->val);
                pre = cur;
            }
        }
        return res;
    }
};
// @lc code=end
