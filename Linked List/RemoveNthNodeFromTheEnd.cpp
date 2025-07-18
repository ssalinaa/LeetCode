#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(): value(0), next(nullptr) { }
    Node(int value) : value(value), next(nullptr) { }
    Node(int value, Node* next) : value(value), next(next) { }
};

Node* removeNthNode(Node* list, int n) {
    Node* newList = new Node(0);
    newList->next = list;
    Node* first = newList;
    Node* second = newList;

    for (size_t i = 0; i < n; i++)
    {
        first = first->next;
    }
    while(first->next && second) {
        first = first->next;
        second = second->next;
    }
    Node* toBeDeleted = second->next;
    second->next = toBeDeleted->next;
    delete toBeDeleted;

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
    list1->next->next->next->next = new Node(5);

    Node* newList1 = removeNthNode(list1, 2);
    printList(newList1);
    
    deallocate(list1);
    deallocate(newList1);

    return 0;
}