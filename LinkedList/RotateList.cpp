#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) { }
    ListNode(int value) : value(value), next(nullptr) { }
    ListNode(int value, ListNode* next) : value(value), next(next) { }
};

void rotateList(ListNode*& head, int k) {
    if(!head || k == 0) return;

    ListNode* current = head;
    ListNode* previous = nullptr;
    for(int i = 0; i < k; i++) {

        while(current->next) {
            previous = current;
            current = current->next;
        }
        previous->next = nullptr;
        previous = nullptr;
        current->next = head;
        head = current;
    }
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
    list1->next->next->next->next = new ListNode(5);

    rotateList(list1, 2);
    printList(list1);

    return 0;
}