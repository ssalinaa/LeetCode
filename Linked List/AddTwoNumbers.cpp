#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(): value(0), next(nullptr) { }
    Node(int value) : value(value), next(nullptr) { }
    Node(int value, Node* next) : value(value), next(next) { }
};

Node* addTwoNumbers(Node* list1, Node* list2) {
    Node* newList = new Node();
    Node* current = newList;
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
        current->next = new Node(sum % 10);
        current = current->next;
    }
    return newList->next;
}

void printList(Node* head) {
    while(head) {
        std::cout << head->value << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

void deallocate(Node* head) {
    while(head) {
        Node* toBeDeleted = head;
        head = head->next;
        delete toBeDeleted;
    }
}

int main() {

    Node* list1 = new Node(2);
    list1->next = new Node(4);
    list1->next->next = new Node(3);

    Node* list2 = new Node(5);
    list2->next = new Node(6);
    list2->next->next = new Node(4);

    Node* sumList1 = addTwoNumbers(list1, list2);
    printList(sumList1);
    
    deallocate(list1);
    deallocate(list2);
    deallocate(sumList1);

    Node* list3 = new Node(9);
    list3->next = new Node(9);
    list3->next->next = new Node(9);
    list3->next->next->next = new Node(9);
    list3->next->next->next->next = new Node(9);
    list3->next->next->next->next->next = new Node(9);
    list3->next->next->next->next->next->next = new Node(9);

    Node* list4 = new Node(9);
    list4->next = new Node(9);
    list4->next->next = new Node(9);
    list4->next->next->next = new Node(9);

    Node* sumList2 = addTwoNumbers(list3, list4);
    printList(sumList2);

    deallocate(list3);
    deallocate(list4);
    deallocate(sumList2);

    return 0;
}