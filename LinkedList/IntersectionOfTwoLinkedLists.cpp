#include <iostream>

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
        head = head->next;
        length++;
    }
    return length;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int size1 = getLength(headA);
    int size2 = getLength(headB);

    while(size1 > size2) {
        headA = headA->next;
        size1--;
    }
    while(size2 > size1) {
        headB = headB->next;
        size2--;
    }
    while(headA && headB) {
        if(headA == headB) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return nullptr;
}


int main() {

    ListNode* commonPart1 = new ListNode(8);
    commonPart1->next = new ListNode(4);
    commonPart1->next->next = new ListNode(4);

    ListNode* list1 = new ListNode(4);
    list1->next = new ListNode(1);
    list1->next->next = commonPart1;

    ListNode* list2 = new ListNode(5);
    list2->next = new ListNode(6);
    list2->next->next = new ListNode(1);
    list2->next->next->next = commonPart1;

    ListNode* intersectionNode1 = getIntersectionNode(list1, list2);
    if(intersectionNode1) {
        std::cout << "Intersection at node with value: " << intersectionNode1->value << std::endl;
    } else {
        std::cout << "No intersection found. " << std::endl;
    }

    ListNode* commonPart2 =new ListNode(2);
    commonPart2->next = new ListNode(4);

    ListNode* list3 = new ListNode(1);
    list3->next = new ListNode(9);
    list3->next->next = new ListNode(1);
    list3->next->next->next = commonPart2;

    ListNode* list4 = new ListNode(3);
    list4->next = commonPart2;

    ListNode* intersectionNode2 = getIntersectionNode(list3, list4);
    if(intersectionNode2) {
        std::cout << "Intersection at node with value: " << intersectionNode2->value << std::endl;
    } else {
        std::cout << "No intersection found. " << std::endl;
    }
   
    return 0;
}