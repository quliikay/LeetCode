/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> que;
        if(root) que.emplace(root);
        while (!que.empty())
        {
            int size = que.size();
            for(int i=0;i<size;i++){
                TreeNode* cur = que.front();
                que.pop();
                if(cur->left) que.emplace(cur->left);
                if(cur->right) que.emplace(cur->right);
            }
            res++;
        }
        return res;
    }
};
// @lc code=end
