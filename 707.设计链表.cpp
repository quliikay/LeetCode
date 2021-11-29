/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MyLinkedList {
private:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode()
            : val(0), next(NULL){};
        LinkedNode(int x)
            : val(x), next(NULL){};
        LinkedNode(int x, LinkedNode* y)
            : val(x), next(y){};
    };
    int _size;
    LinkedNode* _dummyHead;

public:
    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }

    int get(int index) {
        if (index < 0 || index > _size - 1)
            return -1;
        LinkedNode* cur = _dummyHead->next;
        while (index--)
            cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val) {
        LinkedNode* node = new LinkedNode(val, _dummyHead->next);
        _dummyHead->next = node;
        _size++;
    }

    void addAtTail(int val) {
        LinkedNode* node = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = node;
        _size++;
    }

    void addAtIndex(int index, int val) {
        if (index > _size)
            return;
        LinkedNode* node = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (index--)
            cur = cur->next;
        node->next = cur->next;
        cur->next = node;
        _size++;
    }

    void deleteAtIndex(int index) {
        if (index >= _size || index < 0)
            return;
        LinkedNode* cur = _dummyHead;
        while (index--)
            cur = cur->next;
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
