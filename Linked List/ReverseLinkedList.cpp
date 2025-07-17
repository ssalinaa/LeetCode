#include <iostream>

struct Node {
    int value;
    Node* next;
    Node() : value(0), next(nullptr) { }
    Node(int value) : value(value), next(nullptr) { }
    Node(int value, Node* next) : value(value), next(next) { }
};

Node* reverseList(Node* head) {
    if(!head) return head;
    
    Node* current = head;
    Node* previous = nullptr;
    Node* next;
    
    while(current) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}

void printList(Node* head) {
    Node* current = head;
    while(current) {
        std::cout << current->value << " -> ";
        current = current->next;
    }
    std::cout << "nullptr";
    std::cout << std::endl;
}

void deallocate(Node* head) {
    while(head) {
        Node* toBeDeleted = head;
        head = head->next;
        delete toBeDeleted;
    }
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(6);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(6);

    Node* reversedList = reverseList(head);
    printList(reversedList);
    deallocate(head);
    deallocate(reversedList);

    return 0;
}