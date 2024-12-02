#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) { }
    ListNode(int value) : value(value), next(nullptr) { }
    ListNode(int value, ListNode* next) : value(value), next(next) { }
};

ListNode* reverseLinkedList(ListNode* head) {
    if(!head) return head;
    ListNode* current = head;
    ListNode* previous = nullptr;
    ListNode* next = nullptr;
    while(current) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}

void printList(ListNode* head) {
    while(head) {
        std::cout << head->value << " -> ";
        head = head->next;
    }
    std::cout << "nullptr";
}

void deallocate(ListNode* head) {
    while(head) {
        ListNode* toBeDeleted = head;
        head = head->next;
        delete toBeDeleted;
    }
}

int main() {

    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);

    ListNode* reversedLinkedList = reverseLinkedList(list);
    printList(reversedLinkedList);
    deallocate(list);
    deallocate(reversedLinkedList);

    return 0;
}