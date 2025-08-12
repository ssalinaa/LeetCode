#include <iostream>

struct Node {
    int value;
    Node* next;
    Node* previous;

    Node(int value) : value(value), next(nullptr), previous(nullptr) { }
    Node(int value, Node* next, Node* previous) : value(value), next(next), previous(previous) { }
};

Node* deletionAtBeginning(Node* head) {
    if(!head) return head;

    Node* toBeDeleted = head;
    head = head->next;
    if(head) {
        head->previous = nullptr;
    }
    delete toBeDeleted;
    return head;
}

Node* deletionAtEnd(Node* head) {
    if(!head) return head;
    if(!head->next) {
        delete head;
        return nullptr;
    }

    Node* current = head;
    while(current->next) {
        current = current->next;
    }
    current->previous->next = nullptr;
    delete current;
    return head; 
}

Node* deletionAtSpecificPosition(Node* head, int position) {
    if(!head) return head;

    Node* current = head;
    for (size_t i = 1; i < position && current; i++)
    {
        current = current->next;
    }
    if(!current) {
        return head;
    }
    if(current->previous) {
        current->previous->next = current->next;
    }
    if(current->next) {
        current->next->previous = current->previous;
    }
    delete current;
    return head;
}

void printList(Node* head) {
    while(head) {
        std::cout << head->value << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->previous = head;
    head->next->next = new Node(3);
    head->next->next->previous = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->previous = head->next->next;

    std::cout << "Original list: ";
    printList(head);

    std::cout << "List after deletion at the beginning: ";
    head = deletionAtBeginning(head);
    printList(head); 

    std::cout << "List after deletion at the end: ";
    head = deletionAtEnd(head);
    printList(head); 

    std::cout << "List after deletion at position 4: ";
    head = deletionAtSpecificPosition(head, 2);
    printList(head); 

    return 0;
}