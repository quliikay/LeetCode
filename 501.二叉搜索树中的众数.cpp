/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    TreeNode* pre = nullptr;
    int count = 0;
    int countMax = 0;
    vector<int> result;
    vector<int> findMode(TreeNode* root) {
        traversal(root);
        return result;
    }
    void traversal(TreeNode* cur) {
        if (!cur)
            return;
        traversal(cur->left);
        if (pre != nullptr && pre->val == cur->val)
            count++;
        else
            count = 1;
        if (count == countMax)
            result.push_back(cur->val);
        if (count > countMax) {
            result.clear();
            result.push_back(cur->val);
            countMax = count;
        }
        pre = cur;
        traversal(cur->right);
    }
};
// @lc code=end
