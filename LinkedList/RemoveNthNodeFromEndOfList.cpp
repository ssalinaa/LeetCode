#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) { }
    ListNode(int value) : value(value), next(nullptr) { }
    ListNode(int value, ListNode* next) : value(value), next(next) { }
};

ListNode* removeNthNode(ListNode* head, int N) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;

    for(int i = 0; i < N; i++) {
        first = first->next;
    }
    while(first->next && second) {
        first = first->next;
        second = second->next;
    }
    ListNode* toBeDeleted = second->next;
    second->next = toBeDeleted->next;
    delete toBeDeleted;

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
    list1->next->next->next->next = new ListNode(5);

    ListNode* newList1 = removeNthNode(list1, 2);
    printList(newList1);        

    return 0;
}