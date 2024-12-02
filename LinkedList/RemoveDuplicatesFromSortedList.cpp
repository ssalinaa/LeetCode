#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) { }
    ListNode(int value) : value(value), next(nullptr) { }
    ListNode(int value, ListNode* next) : value(value), next(next) { }
};

ListNode* removeDuplicates(ListNode* head) {
    if(!head || !head) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* current = head;
    while(current && current->next) {
        if(current->value == current->next->value) {
            ListNode* toBeDeleted = current->next;
            current->next = toBeDeleted->next;
            delete toBeDeleted;
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
    std::cout << "nullptr";
    std::cout << std::endl;
}

void deallocate(ListNode* head) {
    while(head) {
        ListNode* toBeDeleted = head;
        head = head->next;
        delete toBeDeleted;
    }
}

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(2);

    ListNode* newList1 = removeDuplicates(list1);
    printList(newList1);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(1);
    list2->next->next = new ListNode(2);
    list2->next->next->next = new ListNode(3);
    list2->next->next->next->next = new ListNode(3);

    ListNode* newList2 = removeDuplicates(list2);
    printList(newList2);

    deallocate(list1);
    deallocate(newList1);
    deallocate(list2);
    deallocate(newList2);

    return 0;
}