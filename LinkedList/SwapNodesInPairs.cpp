#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) { }
    ListNode(int value) : value(value), next(nullptr) { }
    ListNode(int value, ListNode* next) : value(value), next(next) { }
};

ListNode* swapNodes(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* previous = dummy;

    while(previous->next && previous->next->next) {
        ListNode* first = previous->next;
        ListNode* second = previous->next->next;

        first->next = second->next;
        second->next = first;

        previous->next = second;
        previous = first;
    }
    return dummy->next;
}

void printList(ListNode* head) {
    while(head) {
        std::cout << head->value << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {

    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);

    ListNode* swappedNodes1 = swapNodes(list1);
    printList(swappedNodes1);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(2);
    list2->next->next = new ListNode(3);

    ListNode* swappedNodes2 = swapNodes(list2);
    printList(swappedNodes2);

    return 0;
}