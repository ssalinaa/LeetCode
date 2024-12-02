#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) { }
    ListNode(int value) : value(value), next(nullptr) { }
    ListNode(int value, ListNode* next) : value(value), next(next) { }
};

ListNode* removeElements(ListNode* head, int value) {
    if(!head) return head;
    if(head && head->value == value) {
        ListNode* toBeDeleted = head;
        head = head->next;
        delete toBeDeleted;
    }
    ListNode* current = head;
    while(current && current->next) {
        if(current->next->value == value) {
            ListNode* toBeDeleted = current->next;
            current->next = toBeDeleted->next;
            delete toBeDeleted;
        } else {
            current = current->next;
        }
    }
    return head;
}

void printList(ListNode* head) {
    while(head) {
        std::cout << head->value << " -> ";
        head = head->next;
    }
    std::cout << "nullptr";
}

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(6);
    list1->next->next->next = new ListNode(3);
    list1->next->next->next->next = new ListNode(4);
    list1->next->next->next->next->next = new ListNode(5);
    list1->next->next->next->next->next->next = new ListNode(6);

    ListNode* list2 = removeElements(list1, 6);
    printList(list2);

    return 0;
}