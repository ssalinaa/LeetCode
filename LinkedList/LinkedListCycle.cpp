#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) { }
    ListNode(int value) : value(value), next(nullptr) { }
    ListNode(int value, ListNode* next) : value(value), next(next) { }
};

bool hasCycle(ListNode* head) {
    if(!head || !head->next) return false;

    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {
    ListNode* list1 = new ListNode(3);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(0);
    list1->next->next->next = new ListNode(-4);
    list1->next->next->next->next = list1->next;

    std::cout << std::boolalpha << hasCycle(list1) << std::endl;

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(2);
    list2->next->next = list2;

    std::cout << std::boolalpha << hasCycle(list2) << std::endl;

    ListNode* list3 = new ListNode(1);
    std::cout << std::boolalpha << hasCycle(list3) << std::endl;

    return 0;
}