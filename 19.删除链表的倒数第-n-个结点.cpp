/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
// Definition for singly-linked list.
#include <bits/stdc++.h>
using namespace std;
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyIndex = new ListNode(0, head);
        ListNode* fastIndex = dummyIndex;
        ListNode* slowIndex = dummyIndex;
        while (--n)
            fastIndex = fastIndex->next;
        while (fastIndex->next->next != NULL) {
            fastIndex = fastIndex->next;
            slowIndex = slowIndex->next;
        }
        slowIndex->next = slowIndex->next->next;
        return dummyIndex->next;
    }
};
// @lc code=end
