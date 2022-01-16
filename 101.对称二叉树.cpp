/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        if (root) {
            que.emplace(root->left);
            que.emplace(root->right);
        }
        while (!que.empty()) {
            TreeNode* leftNode = que.front();
            que.pop();
            TreeNode* rightNode = que.front();
            que.pop();
            if (!leftNode && !rightNode)
                continue;
            else if (!leftNode && rightNode)
                return false;
            else if (leftNode && !rightNode)
                return false;
            else if (leftNode->val != rightNode->val)
                return false;
            que.push(leftNode->left);
            que.push(rightNode->right);
            que.push(leftNode->right);
            que.push(rightNode->left);
        }
        return true;
    }
};
// @lc code=end
