#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) { }
    ListNode(int value) : value(value), next(nullptr) { }
    ListNode(int value, ListNode* next) : value(value), next(next) { }
};

void reorderList(ListNode* head) {
    if(!head || !head->next || !head->next->next) return;

    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* previous = nullptr;
    ListNode* current = slow->next;
    slow->next = nullptr;
    while(current) {
        ListNode* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    ListNode* first = head;
    ListNode* second = previous;
    while(second) {
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
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
    reorderList(list1);
    printList(list1);    

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(2);
    list2->next->next = new ListNode(3);
    list2->next->next->next = new ListNode(4);
    list2->next->next->next->next = new ListNode(5);
    reorderList(list2);
    printList(list2);    

    return 0;
}