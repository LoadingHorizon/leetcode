#include <cassert>
#include "add_two_numbers.h"

class TestSolution {
public:
    static void test1() {
        ListNode* list1 = new ListNode(2);
        list1->next = new ListNode(4);
        list1->next->next = new ListNode(3);

        ListNode* list2 = new ListNode(5);
        list2->next = new ListNode(6);
        list2->next->next = new ListNode(4);

        ListNode* list = _solution.addTwoNumbers(list1, list2);

        assert(list->val == 7);
        assert(list->next->val == 0);
        assert(list->next->next->val == 8);
    }
    static void test2() {
        ListNode* list1 = new ListNode(1);
        list1->next = new ListNode(8);

        ListNode* list2 = new ListNode(0);

        ListNode* list = _solution.addTwoNumbers(list1, list2);

        assert(list->val == 1);
        assert(list->next->val == 8);
    }

private:
        static Solution _solution;
};

Solution TestSolution::_solution;


int main() {
    TestSolution::test1();
    TestSolution::test2();

    return 0;
}
