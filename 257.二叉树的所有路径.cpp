/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    // vector<string> binaryTreePaths(TreeNode* root) {
    //     vector<string> res;
    //     vector<int> path;
    //     if (!root)
    //         return res;
    //     traversal(root, path, res);
    //     return res;
    // }
    // void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
    //     path.push_back(cur->val);
    //     if (cur->left == nullptr && cur->right == nullptr) {
    //         string sPath;
    //         for (int i = 0; i < path.size() - 1; i++) {
    //             sPath += to_string(path[i]);
    //             sPath += "->";
    //         }
    //         sPath += to_string(path[path.size() - 1]);
    //         result.push_back(sPath);
    //     }
    //     if (cur->left) {
    //         traversal(cur->left, path, result);
    //         path.pop_back();
    //     }
    //     if (cur->right) {
    //         traversal(cur->right, path, result);
    //         path.pop_back();
    //     }
    // }
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<TreeNode*> treeSt;
        stack<string> pathSt;
        vector<string> res;
        if (root) {
            treeSt.push(root);
            pathSt.push(to_string(root->val));
        }
        while (!treeSt.empty()) {
            TreeNode* cur = treeSt.top();
            treeSt.pop();
            string path = pathSt.top();
            pathSt.pop();
            if (!cur->left && !cur->right)
                res.push_back(path);
            if (cur->right) {
                treeSt.emplace(cur->right);
                pathSt.emplace(path + "->" + to_string(cur->right->val));
            }
            if (cur->left) {
                treeSt.emplace(cur->left);
                pathSt.emplace(path + "->" + to_string(cur->left->val));
            }
        }
        return res;
    }
};
// @lc code=end
