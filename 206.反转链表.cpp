/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    // ListNode* reverseList(ListNode* head) {
    //     if (head == NULL || head->next == NULL)
    //         return head;
    //     ListNode* p = reverseList(head->next);
    //     head->next->next = head;
    //     head->next = NULL;
    //     return p;
    // }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp = new ListNode();
        while (curr != NULL) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        delete curr, temp;
        return prev;
    }
};
// @lc code=end
