/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode()
//         : val(0), next(nullptr) {}
//     ListNode(int x)
//         : val(x), next(nullptr) {}
//     ListNode(int x, ListNode* next)
//         : val(x), next(next) {}
// };

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyNode = new ListNode(-1, head);
        ListNode* pre = dummyNode;

       for(int i=0;i<left-1;i++)
           pre = pre->next;

        ListNode* leftNode = pre->next;
        ListNode* rightNode = dummyNode;
        for(int i=0;i<right;i++)
            rightNode = rightNode->next;
        ListNode* cur = rightNode->next;

        rightNode->next = nullptr;
        pre->next = nullptr;
        reverseList(leftNode);
        pre->next = rightNode;
        leftNode->next = cur;

        return dummyNode->next;
    }
};
// @lc code=end
