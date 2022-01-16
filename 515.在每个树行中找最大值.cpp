/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        if(root) que.emplace(root);
        while (!que.empty())
        {
            int size = que.size();
            int maxValue = INT_MIN;
            for(int i=0;i<size;i++){
                TreeNode* cur = que.front();
                que.pop();
                maxValue = maxValue>cur->val?maxValue:cur->val;
                if(cur->left) que.emplace(cur->left);
                if(cur->right) que.emplace(cur->right);
            }
            res.emplace_back(maxValue);
        }
        return res;
    }
};
// @lc code=end
