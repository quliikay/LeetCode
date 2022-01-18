/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x), left(NULL), right(NULL) {}
};

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if (!root||root==p||root==q)
//             return root;
//         if (root->val < max(p->val, q->val) && root->val > min(q->val, p->val))
//             return root;
//         if (root->val > max(p->val, q->val))
//             return lowestCommonAncestor(root->left, p, q);
//         if (root->val < min(p->val, q->val))
//             return lowestCommonAncestor(root->right, p, q);
//     }
// };
class Solution {
public:
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if (!root || root == p || root == q)
    //         return root;
    //     else if (root->val > max(p->val, q->val))
    //         return lowestCommonAncestor(root->left, p, q);
    //     else if (root->val < min(p->val, q->val))
    //         return lowestCommonAncestor(root->right, p, q);
    //     else
    //         return root;
    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stk;
        if (root)
            stk.push(root);
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            if (cur->val > max(p->val, q->val))
                stk.push(cur->left);
            else if (cur->val < min(p->val, q->val))
                stk.push(cur->right);
            else
                return cur;
        }
        return root;
    }
};
// @lc code=end
