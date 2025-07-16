#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(int value, Node* next = nullptr) {
        this->value = value;
        this->next = next;
    }
};

Node* reverseRecursive(Node* head) {
    if(!head || !head->next) return head;
    Node* rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}

void printList(Node* head) {
    Node* current = head;
    while(current) {
        std::cout << current->value << " ";
        current = current->next;  
    }
    std::cout << std::endl;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original list: ";
    printList(head);
    std::cout << "After reversing list: ";
    head = reverseRecursive(head);
    printList(head);

    return 0;
}