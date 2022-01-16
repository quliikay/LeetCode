/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        int depth = 0;
        if (root)
            que.emplace(root);
        while (!que.empty()) {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                if (cur->left)
                    que.emplace(cur->left);
                if (cur->right)
                    que.emplace(cur->right);
                if (cur->right == NULL && cur->left == NULL)
                    return depth;
            }
        }
        return depth;
    }
};
// @lc code=end
