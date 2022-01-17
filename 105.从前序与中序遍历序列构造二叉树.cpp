/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return traversal(preorder, inorder);
    }
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return nullptr;
        int rootValue = preorder[0];
        TreeNode* root = new TreeNode(rootValue);
        if (preorder.size() == 1)
            return root;
        int delimiterIndex;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == rootValue) {
                delimiterIndex = i;
                break;
            }
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());
        vector<int> preorder1(preorder.begin() + 1, preorder.end());
        vector<int> leftpreorder(preorder1.begin(), preorder1.begin() + leftInorder.size());
        vector<int> rightpreorder(preorder1.begin() + leftInorder.size(), preorder1.end());
        root->right = traversal(rightpreorder, rightInorder);
        root->left = traversal(leftpreorder, leftInorder);
        return root;
    }
};
// @lc code=end
