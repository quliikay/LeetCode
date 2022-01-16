/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node()
        : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val)
        : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root)
            que.emplace(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                Node* cur = que.front();
                que.pop();
                if (i < size - 1)
                    cur->next = que.front();
                if (cur->left)
                    que.emplace(cur->left);
                if (cur->right)
                    que.emplace(cur->right);
            }
        }
        return root;
    }
};
// @lc code=end
