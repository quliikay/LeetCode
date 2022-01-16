/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     Traversal(root, res);
    //     return res;
    // }
    // vector<int> Traversal(TreeNode* cur, vector<int>& res) {
    //     if (cur == NULL)
    //         return res;
    //     res.emplace_back(cur->val);
    //     Traversal(cur->left, res);
    //     Traversal(cur->right, res);
    //     return res;
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     stack<TreeNode* > stk;
    //     vector<int> res;
    //     if(root==NULL) return res;
    //     TreeNode* cur = root;
    //     stk.push(cur);
    //     while(!stk.empty()){
    //         cur = stk.top();
    //         stk.pop();
    //         res.emplace_back(cur->val);
    //         if(cur->right) stk.push(cur->right);
    //         if(cur->left) stk.push(cur->left);
    //     }
    //     return res;
    // }
    vector<int> preorderTraversal(TreeNode* root) {
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
                if (cur->left)
                    stk.push(cur->left);
                stk.push(cur);
                stk.push(NULL);
            } else {
                res.emplace_back(stk.top()->val);
                stk.pop();
            }
        }
        return res;
    }
};
// @lc code=end
