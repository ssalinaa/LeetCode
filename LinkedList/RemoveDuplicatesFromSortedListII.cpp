#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) { }
    ListNode(int value) : value(value), next(nullptr) { }
    ListNode(int value, ListNode* next) : value(value), next(next) { }
};

ListNode* removeDuplicates(ListNode* head) {
    if(!head) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* current = head;
    ListNode* previous = dummy;

    while(current && current->next) {
        if(current->value == current->next->value) {
            while(current->next && current->value == current->next->value) {
                current = current->next;
            }
            previous->next = current->next;
        }
        else {
            previous = previous->next;
        }
        current = current->next;
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
    list1->next->next->next = new ListNode(3);
    list1->next->next->next->next = new ListNode(4);
    list1->next->next->next->next->next = new ListNode(4);
    list1->next->next->next->next->next->next = new ListNode(5);

    ListNode* newList1 = removeDuplicates(list1);
    printList(newList1);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(1);
    list2->next->next = new ListNode(1);
    list2->next->next->next = new ListNode(2);
    list2->next->next->next->next = new ListNode(3);

    ListNode* newList2 = removeDuplicates(list2);
    printList(newList2);

    return 0;
}