#include <iostream>
#include <cmath>

struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) { }
    ListNode(int value) : value(value), next(nullptr) { }
    ListNode(int value, ListNode* next) : value(value), next(next) { }
};

int getLength(ListNode* head) {
    int length = 0;
    while(head) {
        length++;
        head = head->next;
    }
    return length;
}

int getDecimalValue(ListNode* head) {
    if(!head) return 0;
    int result = 0;
    int length = getLength(head);
    ListNode* current = head;
    while(current) {
        result += current->value * std::pow(2, length - 1);
        length--;
        current = current->next;
    }
    return result;
}

int main() {
    
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(0);
    list1->next->next = new ListNode(1);
    std::cout << getDecimalValue(list1) << std::endl;

    ListNode* list2 = new ListNode(0);
    std::cout << getDecimalValue(list2) << std::endl;

    return 0;
}