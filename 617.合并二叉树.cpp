/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return traversal(root1,root2);
    }
    TreeNode* traversal(TreeNode* root1, TreeNode* root2){
        if(!root1) return root2;
        if(!root2) return root1;
        TreeNode* root = new TreeNode(root1->val+root2->val);
        root->right = traversal(root1->right, root2->right);
        root->left = traversal(root1->left,root2->left);
        return root;

    }
};
// @lc code=end
