/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     Traversal(root, res);
    //     return res;
    // }
    // vector<int> Traversal(TreeNode* cur, vector<int>& res) {
    //     if (cur == NULL)
    //         return res;
    //     Traversal(cur->left, res);
    //     Traversal(cur->right, res);
    //     res.emplace_back(cur->val);
    //     return res;
    // }
    // vector<int> postorderTraversal(TreeNode* root) {
    //     stack<TreeNode*> stk;
    //     vector<int> res;
    //     if(root==NULL) return res;
    //     TreeNode* cur = root;
    //     stk.push(cur);
    //     while(!stk.empty()){
    //         cur = stk.top();
    //         stk.pop();
    //         res.emplace_back(cur->val);
    //         if(cur->left) stk.push(cur->left);
    //         if(cur->right) stk.push(cur->right);
    //     }
    //     reverse(res.begin(),res.end());
    //     return res;
    // }
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        if (root != NULL)
            stk.push(root);
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            if (cur != NULL) {
                stk.push(cur);
                stk.push(NULL);
                if (cur->right)
                    stk.push(cur->right);
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
