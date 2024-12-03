#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) { }
    ListNode(int value) : value(value), next(nullptr) { }
    ListNode(int value, ListNode* next) : value(value), next(next) { }
};

ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    int carry = 0;
    while(list1 || list2 || carry) {
        int sum = carry;
        if(list1) {
            sum += list1->value;
            list1 = list1->next;
        }
        if(list2) {
            sum += list2->value;
            list2 = list2->next;
        }
        carry = sum / 10;
        current->next = new ListNode(sum % 10);
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

    ListNode* list1 = new ListNode(2);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(3);

    ListNode* list2 = new ListNode(5);
    list2->next = new ListNode(6);
    list2->next->next = new ListNode(4);

    ListNode* sum1 = addTwoNumbers(list1, list2);
    printList(sum1);

    ListNode* list3 = new ListNode(9);
    list3->next = new ListNode(9);
    list3->next->next = new ListNode(9);
    list3->next->next->next = new ListNode(9);
    list3->next->next->next->next = new ListNode(9);
    list3->next->next->next->next->next = new ListNode(9);
    list3->next->next->next->next->next->next = new ListNode(9);

    ListNode* list4 = new ListNode(9);
    list4->next = new ListNode(9);
    list4->next->next = new ListNode(9);
    list4->next->next->next = new ListNode(9);

    ListNode* sum2 = addTwoNumbers(list3, list4);
    printList(sum2);

    return 0;
}