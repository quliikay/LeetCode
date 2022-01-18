/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size() - 1);
    }
    TreeNode* traversal(const vector<int>& nums, int startIndex, int endIndex) {
        if (endIndex < startIndex)
            return nullptr;
        if (endIndex == startIndex) {
            TreeNode* root = new TreeNode(nums[startIndex]);
            return root;
        }
        int max = INT64_MIN;
        int splitIndex = 0;
        for (int i = startIndex; i <= endIndex; i++) {
            if (max < nums[i]) {
                max = nums[i];
                splitIndex = i;
            }
        }
        TreeNode* root = new TreeNode(nums[splitIndex]);
        int leftStartIndex = startIndex;
        int leftEndIndex = splitIndex - 1;
        int rightStartIndex = splitIndex + 1;
        int rightEndIndex = endIndex;
        root->left = traversal(nums, leftStartIndex, leftEndIndex);
        root->right = traversal(nums, rightStartIndex, rightEndIndex);
        return root;
    }
};
// @lc code=end
