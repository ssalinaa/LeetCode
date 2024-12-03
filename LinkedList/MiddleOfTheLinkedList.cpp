#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) { }
    ListNode(int value) : value(value), next(nullptr) { }
    ListNode(int value, ListNode* next) : value(value), next(next) { }
};

ListNode* getMiddle(ListNode* head) {
    if(!head) return head;
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void printList(ListNode* head) {
    while (head) {
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

    ListNode* middle1 = getMiddle(list1);
    printList(middle1);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(2);
    list2->next->next = new ListNode(3);
    list2->next->next->next = new ListNode(4);
    list2->next->next->next->next = new ListNode(5);
    list2->next->next->next->next->next = new ListNode(6);

    ListNode* middle2 = getMiddle(list2);
    printList(middle2);

    return 0;
}