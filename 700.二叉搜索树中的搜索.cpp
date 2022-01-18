/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    // TreeNode* searchBST(TreeNode* root, int val) {
    //     stack<TreeNode*> stk;
    //     if (root)
    //         stk.push(root);
    //     while (!stk.empty()) {
    //         TreeNode* cur = stk.top();
    //         stk.pop();
    //         if (cur->val == val)
    //             return cur;
    //         else if (cur->val < val) {
    //             if (cur->right)
    //                 stk.push(cur->right);
    //         }
    //         else {
    //             if (cur->left)
    //                 stk.push(cur->left);
    //         }
    //     }
    //     return nullptr;
    // }
    TreeNode* searchBST(TreeNode* root, int val) {
        return traversal(root,val);
    }
    TreeNode* traversal(TreeNode* root, int val) {
        if (root->val == val)
            return root;
        if (root->val > val && root->left) 
            return traversal(root->left, val);
        if (root->val < val && root->right)
            return traversal(root->right, val);
        return nullptr;
    }
};
// @lc code=end
