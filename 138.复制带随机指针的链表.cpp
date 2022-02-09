/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

class Solution {
public:
    unordered_map<Node*, Node*> cacheNode;
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        if(!cacheNode.count(head)){
            Node* headNew = new Node(head->val);
            cacheNode[head] = headNew;
            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }
        return cacheNode[head];
    }
};
// @lc code=end

