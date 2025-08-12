#include <iostream>

struct Node {
    int value;
    Node* next;
    Node* previous;

    Node(int value) : value(value), next(nullptr), previous(nullptr) { }
    Node(int value, Node* next, Node* previous) : value(value), next(next), previous(previous) { }
};

int findLength(Node* head) {
    int length = 0;
    while(head) {
        length++;
        head = head->next;
    }
    return length;
}

int findLengthRecursive(Node* head) {
    if(!head) return 0;

    return 1 + findLength(head->next);
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
    head->next->previous = head;
    head->next->next = new Node(3);
    head->next->next->previous = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->previous = head->next->next;

    std::cout << "The length of the list is: " << findLength(head) << std::endl;
    std::cout << "The length of the list is: " << findLengthRecursive(head) << std::endl;

    deallocate(head);
    return 0;
}