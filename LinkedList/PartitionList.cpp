#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) { }
    ListNode(int value) : value(value), next(nullptr) { }
    ListNode(int value, ListNode* next) : value(value), next(next) { }
};

ListNode* partitionList(ListNode* head, int x) {
   if(!head) return head;
   ListNode* dummy1 = new ListNode(0);
   ListNode* dummy2 = new ListNode(0);

   ListNode* previous1 = dummy1;
   ListNode* previous2 = dummy2;
   ListNode* current = head;

   while (current) {
        if(current->value < x) {
            previous1->next = current;
            previous1 = previous1->next;
        } else {
            previous2->next = current;
            previous2 = previous2->next;
        }
        current = current->next;
   }
   previous2->next = nullptr;
   previous1->next = dummy2->next;

   return dummy1->next;
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
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(2);
    list1->next->next->next->next = new ListNode(5);
    list1->next->next->next->next->next = new ListNode(2);
    
    ListNode* partition1 = partitionList(list1, 3);
    printList(partition1);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(1);

    ListNode* partition2 = partitionList(list2, 2);
    printList(partition2);

    return 0;
}