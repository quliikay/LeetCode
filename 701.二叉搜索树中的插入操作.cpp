/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    // TreeNode* insertIntoBST(TreeNode* root, int val) {
    //     stack<TreeNode*> stk;
    //     TreeNode* node = new TreeNode(val);
    //     if (root)
    //         stk.push(root);
    //     else
    //         return node;
    //     while (!stk.empty()) {
    //         TreeNode* cur = stk.top();
    //         stk.pop();
    //         if (cur->val > val) {
    //             if (cur->left)
    //                 stk.push(cur->left);
    //             else
    //                 cur->left = node;
    //         } else {
    //             if (cur->right)
    //                 stk.push(cur->right);
    //             else
    //                 cur->right = node;
    //         }
    //     }
    //     return root;
    // }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        if (root->val > val)
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};
// @lc code=end
