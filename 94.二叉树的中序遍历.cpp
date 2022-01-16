/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     Traversal(root, res);
    //     return res;
    // }
    // vector<int> Traversal(TreeNode* cur, vector<int>& res) {
    //     if (cur == NULL)
    //         return res;
    //     Traversal(cur->left, res);
    //     res.emplace_back(cur->val);
    //     Traversal(cur->right, res);
    //     return res;
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     stack<TreeNode*> stk;
    //     vector<int> res;
    //     if (root == NULL)
    //         return res;
    //     TreeNode* cur = root;
    //     while (cur != NULL || !stk.empty()) {
    //         if (cur != NULL) {
    //             stk.push(cur);
    //             cur = cur->left;
    //         } else {
    //             cur = stk.top();
    //             stk.pop();
    //             res.emplace_back(cur->val);
    //             cur = cur->right;
    //         }
    //     }
    //     return res;
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        if (root != NULL)
            stk.push(root);
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            if (cur != NULL) {
                if (cur->right)
                    stk.push(cur->right);
                stk.push(cur);
                stk.push(NULL);
                if (cur->left)
                    stk.push(cur->left);
            } else {
                res.emplace_back(stk.top()->val);
                stk.pop();
            }
        }
        return res;
    }
};
// @lc code=end
