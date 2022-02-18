/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cnt1 = list1;
        ListNode* cnt2 = list2;
        ListNode* head = new ListNode();
        ListNode* temp = head;
        while (cnt1 != NULL && cnt2 != NULL) {
            if (cnt1->val < cnt2->val) {
                temp->next = new ListNode(cnt1->val);
                cnt1 = cnt1->next;
            } else {
                temp->next = new ListNode(cnt2->val);
                cnt2 = cnt2->next;
            }
            temp = temp->next;
        }
        while (cnt1 != NULL) {
            temp->next = new ListNode(cnt1->val);
            cnt1 = cnt1->next;
            temp = temp->next;
        }
        while (cnt2 != NULL) {
            temp->next = new ListNode(cnt2->val);
            cnt2 = cnt2->next;
            temp = temp->next;
        }
        return head->next;
    }
};
// @lc code=end
