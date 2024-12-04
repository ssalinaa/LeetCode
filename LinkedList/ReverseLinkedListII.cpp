#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) { }
    ListNode(int value) : value(value), next(nullptr) { }
    ListNode(int value, ListNode* next) : value(value), next(next) { }
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(!head || left == right) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* previous = dummy;

    for(int i = 1; i < left; i++) {
        previous = previous->next;
    }
    ListNode* current = previous->next;
    ListNode* next = nullptr;
    ListNode* sublist = previous;

    for(int i = 0; i < right - left + 1; i++) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    sublist->next->next = current;
    sublist->next = previous;

    return head;
}


void printList(ListNode* head) {
    while(head) {
        std::cout << head->value << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);
    
    ListNode* reversedList = reverseBetween(list, 2, 4);
    printList(list);

    return 0;
}