#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) { }
    ListNode(int value) : value(value), next(nullptr) { }
    ListNode(int value, ListNode* next) : value(value), next(next) { }
};

bool isPalindromeLinkedList(ListNode* head) {
    if(!head || !head->next) return true;

    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* current = slow;
    ListNode* temp = nullptr;
    while(current) {
        ListNode* nextNode = current->next;
        current->next = temp;
        temp = current;
        current = nextNode;
    }

    ListNode* firstHalf = head;
    ListNode* secondHalf = temp;
    while(secondHalf) {
        if(firstHalf->value != secondHalf->value) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}

int main() {

    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(2);
    list1->next->next->next = new ListNode(1);
    std::cout << std::boolalpha << isPalindromeLinkedList(list1) << std::endl;

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(2);
    std::cout << std::boolalpha << isPalindromeLinkedList(list2) << std::endl;

    return 0;
}