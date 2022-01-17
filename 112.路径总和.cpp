/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     if (!root)
    //         return false;
    //     return traversal(root, targetSum);
    // }
    // bool traversal(TreeNode* cur, int count) {
    //     if (!cur->left && !cur->right && count - cur->val != 0)
    //         return false;
    //     if (!cur->left && !cur->right && count - cur->val == 0)
    //         return true;
    //     if (cur->left) {
    //         if (traversal(cur->left, count - cur->val))
    //             return true;
    //     }
    //     if (cur->right) {
    //         if (traversal(cur->right, count - cur->val))
    //             return true;
    //     }
    //     return false;
    // }
    bool hasPathSum(TreeNode* root, int targetSum) {
        stack<pair<TreeNode*, int>> stk;
        if (root)
            stk.push(pair<TreeNode*, int>(root, root->val));
        while (!stk.empty()) {
            auto cur = stk.top();
            stk.pop();
            if (cur.first) {
                if (!cur.first->left && !cur.first->right && cur.second == targetSum)
                    return true;
                if (cur.first->left)
                    stk.push(pair<TreeNode*, int>(cur.first->left, cur.first->left->val + cur.second));
                if (cur.first->right)
                    stk.push(pair<TreeNode*, int>(cur.first->right, cur.first->right->val + cur.second));
                stk.push(pair<TreeNode*, int>(cur.first, cur.second));
                stk.push(pair<TreeNode*, int>(nullptr, 1));
            } else {
                cur = stk.top();
                stk.pop();
            }
        }
        return false;
    }
};
// @lc code=end
