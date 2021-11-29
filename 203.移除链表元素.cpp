/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
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

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* temp = dummyHead;
        while (temp->next != NULL) {
            if (temp->next->val == val)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
// @lc code=end
