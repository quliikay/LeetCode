/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode(int x)
//         : val(x), next(NULL) {}
// };
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if (!head)
            return false;
        do {
            if (slow->next)
                slow = slow->next;
            else
                return false;
            if (fast->next && fast->next->next)
                fast = fast->next->next;
            else
                return false;
        } while (slow != fast);
        return true;
    }
};
// @lc code=end
