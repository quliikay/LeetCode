/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traversal(nums, 0, nums.size() - 1);
    }
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left > right)
            return nullptr;
        int splitIndex = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[splitIndex]);
        node->left = traversal(nums, left, splitIndex - 1);
        node->right = traversal(nums, splitIndex + 1, right);
        return node;
    }
};
// @lc code=end
