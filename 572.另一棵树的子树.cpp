/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (isSametree(root, subRoot))
            return true;
        else if (!root || !subRoot)
            return false;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    bool isSametree(TreeNode* l, TreeNode* r) {
        if (!r && !l)
            return true;
        else if (!r || !l)
            return false;
        else if (r->val != l->val)
            return false;
        bool leftSame = isSametree(l->left, r->left);
        bool rightSame = isSametree(l->right, r->right);
        return leftSame && rightSame;
    }
};
// @lc code=end
