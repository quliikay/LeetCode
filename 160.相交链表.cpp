/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lengthA = 0, lengthB = 0;
        ListNode* cntA = headA;
        while (cntA != NULL) {
            cntA = cntA->next;
            lengthA++;
        }
        ListNode* cntB = headB;
        while (cntB != NULL) {
            cntB = cntB->next;
            lengthB++;
        }
        cntA = headA;
        cntB = headB;
        if (lengthB > lengthA) {
            swap(lengthB, lengthA);
            swap(cntA, cntB);
        }
        int gap = lengthA - lengthB;
        while (gap--)
            cntA = cntA->next;
        while (cntA != NULL) {
            if (cntA == cntB)
                return cntA;
            cntA = cntA->next;
            cntB = cntB->next;
        }
        return NULL;
    }
};
// @lc code=end
