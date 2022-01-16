/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int l_height = 0;
        int r_height = 0;
        TreeNode* cur = root;
        while (cur) {
            cur = cur->left;
            l_height++;
        }
        cur = root->right;
        while (cur) {
            cur = cur->right;
            r_height++;
        }
        if (r_height == l_height)
            return (2 << r_height) - 1;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};
// @lc code=end
