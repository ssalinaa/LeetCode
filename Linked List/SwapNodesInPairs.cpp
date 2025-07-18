#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(): value(0), next(nullptr) { }
    Node(int value) : value(value), next(nullptr) { }
    Node(int value, Node* next) : value(value), next(next) { }
};

Node* swapNodes(Node* list) {
    Node* newList = new Node(0);
    newList->next = list;
    Node* previous = newList;

    while(previous->next && previous->next->next) {
        Node* first = previous->next;
        Node* second = previous->next->next;

        first->next = second->next;
        second->next = first;

        previous->next = second;
        previous = first;
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

    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);
    list1->next->next->next = new Node(4);

    Node* newList1 = swapNodes(list1);
    printList(newList1);
    
    deallocate(list1);
    deallocate(newList1);

    return 0;
}