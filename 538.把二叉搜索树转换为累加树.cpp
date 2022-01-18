/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> stk;
        if (root)
            stk.push(root);
        TreeNode* pre = nullptr;
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            if (cur) {
                if (cur->left)
                    stk.push(cur->left);
                stk.push(cur);
                stk.push(nullptr);
                if (cur->right)
                    stk.push(cur->right);
            } else {
                cur = stk.top();
                stk.pop();
                if (pre != nullptr)
                    cur->val = cur->val + pre->val;
                pre = cur;
            }
        }
        return root;
    }
};
// @lc code=end
