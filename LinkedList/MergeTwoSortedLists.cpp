#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) { }
    ListNode(int value) : value(value), next(nullptr) { }
    ListNode(int value, ListNode* next) : value(value), next(next) { }
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    while(list1 && list2) {
        if(list1->value < list2->value) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    if(list1) {
        current->next = list1;
    } else if(list2) {
        current->next = list2;
    }
    return dummy->next;
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
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* mergeList = mergeTwoLists(list1, list2);
    printList(mergeList);

    deallocate(list1);
    deallocate(list2);
    deallocate(mergeList);

    return 0;
}