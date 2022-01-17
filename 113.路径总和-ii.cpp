/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    // struct Node {
    //     TreeNode* node;
    //     int count;
    //     vector<int> path;
    //     Node(TreeNode* node, int count, vector<int> path)
    //         : node(node), count(count), path(path) {}
    // };
    // vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    //     stack<Node> stk;
    //     vector<vector<int>> path;
    //     if (root) {
    //         vector<int> temp;
    //         temp.emplace_back(root->val);
    //         stk.emplace(Node(root, root->val, temp));
    //     }
    //     while (!stk.empty()) {
    //         Node cur = stk.top();
    //         stk.pop();
    //         if (!cur.node->right && !cur.node->left && cur.count == targetSum)
    //             path.emplace_back(cur.path);
    //         if (cur.node->left) {
    //             vector<int> temp = cur.path;
    //             temp.emplace_back(cur.node->left->val);
    //             stk.emplace(Node(cur.node->left, cur.count + cur.node->left->val, temp));
    //         }
    //         if (cur.node->right) {
    //             vector<int> temp = cur.path;
    //             temp.emplace_back(cur.node->right->val);
    //             stk.emplace(Node(cur.node->right, cur.count + cur.node->right->val, temp));
    //         }
    //     }
    //     return path;
    // }
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return res;
        vector<int> temp;
        temp.push_back(root->val);
        traversal(root, targetSum - root->val, temp);
        return res;
    }
    void traversal(TreeNode* cur, int targetSum, vector<int> path) {
        if (!cur->left && !cur->right && targetSum == 0)
            res.emplace_back(path);
        if (cur->left) {
            path.emplace_back(cur->left->val);
            traversal(cur->left, targetSum - cur->left->val, path);
            path.pop_back();
        }
        if (cur->right) {
            path.emplace_back(cur->right->val);
            traversal(cur->right, targetSum - cur->right->val, path);
            path.pop_back();
        }
    }
};
// @lc code=end
