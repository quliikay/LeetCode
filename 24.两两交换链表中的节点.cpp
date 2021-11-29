/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
// Definition for singly-linked list.
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0), next(nullptr) {}
    ListNode(int x)
        : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next)
        : val(x), next(next) {}
};

class Solution {
public:
    // ListNode* swapPairs(ListNode* head) {
    //     if (head == NULL || head->next == NULL)
    //         return head;
    //     ListNode* dummyHead = new ListNode();
    //     ListNode* prev = dummyHead;
    //     ListNode* left = head;
    //     ListNode* right = head->next;
    //     while (true) {
    //         left->next = right->next;
    //         prev->next = right;
    //         right->next = left;
    //         if (left->next == NULL||left->next->next==NULL)
    //             break;
    //         right = left->next->next;
    //         prev = left;
    //         left = left->next;
    //     }
    //     return dummyHead->next;
    // }
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;
        return temp;
    }
};
// @lc code=end
