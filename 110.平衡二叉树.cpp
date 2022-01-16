/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    // bool isBalanced(TreeNode* root) {
    //     if (!root)
    //         return true;
    //     int leftHeight = getHeight(root->left);
    //     int rightHeight = getHeight(root->right);
    //     if (abs(leftHeight - rightHeight) > 1)
    //         return false;
    //     return isBalanced(root->left) && isBalanced(root->right);
    // }
    // int getHeight(TreeNode* root) {
    //     if (!root)
    //         return 0;
    //     int leftHeight = getHeight(root->left);
    //     int rightHeight = getHeight(root->right);
    //     int res = max(leftHeight, rightHeight) + 1;
    //     return res;
    // }
    bool isBalanced(TreeNode* root) {
        stack<TreeNode*> stk;
        if (root)
            stk.push(root);
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            if (cur) {
                if (cur->right)
                    stk.push(cur->right);
                if (cur->left)
                    stk.push(cur->left);
                stk.push(cur);
                stk.push(NULL);
            } else {
                cur = stk.top();
                stk.pop();
                int leftHeight = getHeight(cur->left);
                int rightHeight = getHeight(cur->right);
                if (abs(leftHeight - rightHeight) > 1)
                    return false;
            }
        }
        return true;
    }
    int getHeight(TreeNode* cur) {
        int depth = 0;
        int result = 0;
        stack<TreeNode*> stk;
        if (!cur)
            return 0;
        stk.push(cur);
        while (!stk.empty()) {
            cur = stk.top();
            stk.pop();
            if (cur) {
                depth++;
                stk.push(cur);
                stk.push(NULL);
                if (cur->right)
                    stk.push(cur->right);
                if (cur->left)
                    stk.push(cur->left);
            } else {
                cur = stk.top();
                stk.pop();
                depth--;
            }
            result = result > depth ? result : depth;
        }
        return result;
    }
};
// @lc code=end
