/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x), next(NULL) {}
};

class Solution {
public:
    // ListNode* detectCycle(ListNode* head) {
    //     unordered_set<ListNode*> visited;
    //     while (head != NULL) {
    //         if (visited.count(head))
    //             return head;
    //         visited.insert(head);
    //         head = head->next;
    //     }
    //     return NULL;
    // }
    ListNode* detectCycle(ListNode* head) {
        ListNode* fastIndex = head;
        ListNode* slowIndex = head;
        while (fastIndex != NULL && fastIndex->next != NULL) {
            fastIndex = fastIndex->next->next;
            slowIndex = slowIndex->next;
            if (fastIndex == slowIndex) {
                ListNode* index1 = fastIndex;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return NULL;
    }
};
// @lc code=end
