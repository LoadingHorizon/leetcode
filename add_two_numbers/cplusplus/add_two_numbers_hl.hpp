#include "list_node.h"
#include <iostream>

class Solution {
public:
    explicit Solution() : _head(nullptr) {}
    virtual ~Solution() {
        _clear();
    }

    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        _clear();
        if (list1 == nullptr || list2 == nullptr) {
            return nullptr;
        }

        int val = list1->val + list2->val;
        ListNode* _head(new ListNode(val % 10));
        list1 = list1->next;
        list2 = list2->next;

        ListNode* ptr = _head;
        while (list1 != nullptr && list2 != nullptr) {
            val = list1->val + list2->val + val / 10;
            ptr->next = new ListNode(val % 10);
            ptr = ptr->next;
            list1 = list1->next;
            list2 = list2->next;
        }

        while (list1 != nullptr) {
            val = list1->val + val / 10;
            ptr->next = new ListNode(val % 10);
            ptr = ptr->next;
            list1 = list1->next;
        }

        while (list2 != nullptr) {
            val = list2->val + val / 10;
            ptr->next = new ListNode(val % 10);
            ptr = ptr->next;
            list2 = list2->next;
        }

        if (val / 10 != 0) {
            ptr->next = new ListNode(1);
        }

        return _head;
    }

private:
    void _clear() {
        while (_head != NULL) {
            auto temp = _head;
            _head = _head->next;
            delete temp;
        }
    }

    ListNode* _head;
};
