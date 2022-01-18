/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        stack<TreeNode*> stk;
        if (root)
            stk.emplace(root);
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            if (cur) {
                if (cur->right)
                    stk.emplace(cur->right);
                stk.emplace(cur);
                stk.emplace(nullptr);
                if (cur->left)
                    stk.emplace(cur->left);
            } else {
                cur = stk.top();
                stk.pop();
                if (pre != nullptr && pre->val >= cur->val)
                    return false;
                pre = cur;
            }
        }
        return true;
    }
};
// @lc code=end
