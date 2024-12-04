#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) { }
    ListNode(int value) : value(value), next(nullptr) { }
    ListNode(int value, ListNode* next) : value(value), next(next) { }
};

ListNode* detectCycle(ListNode* head) {
    if(!head || !head->next) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            ListNode* cycleNode = head;
            while(cycleNode != slow) {
                cycleNode = cycleNode->next;
                slow = slow->next;
            }
            return cycleNode;
        }
    }
    return nullptr;
}

int main() {
    ListNode* list1 = new ListNode(3);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(0);
    list1->next->next->next = new ListNode(-4);
    list1->next->next->next = list1->next;

    ListNode* cycleNode = detectCycle(list1);
    if(cycleNode) {
        std::cout << "Cycle starts at node with value: " << cycleNode->value << std::endl;
    } else {
        std::cout << "No cycle found!" << std::endl;
    }

    return 0;
}