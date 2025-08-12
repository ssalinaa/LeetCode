#include <iostream>

struct Node {
    int value;
    Node* next;
    Node* previous;

    Node(int value) : value(value), next(nullptr), previous(nullptr) { }
    Node(int value, Node* next, Node* previous) : value(value), next(next), previous(previous) { }
};

Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    if(head) {
        head->previous = newNode;
    }
    return newNode;
}

Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node(value);
    if(!head) {
        head = newNode;
    } else {
        Node* current = head;
        while(current->next) {
            current = current->next;
        }
        current->next = newNode;
        newNode->previous = current;
    }
    return head;
}

Node* insertAtSpecificPosition(Node* head, int value, int position) {
    Node* newNode = new Node(value);
    if(position == 1) {
        newNode->next = head;
        if(!head) {
            head->previous = newNode;
        }
        head = newNode;
        return head;
    }
    Node* current = head;
    for (size_t i = 1; i < position - 1 && current; i++)
    {
        current = current->next;
    }
    if(!current) {
        std::cout << "Position is out of bounds." << std::endl;
        delete newNode;
        return head;
    }
    newNode->previous = current;
    newNode->next = current->next;
    current->next = newNode;

    if(newNode->next) {
        newNode->next->previous = newNode;
    }
    return head;
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
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->previous = head;
    head->next->next = new Node(3);
    head->next->next->previous = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->previous = head->next->next;

    std::cout << "Original linked list: ";
    printList(head);

    std::cout << "After inserting at the beginning: ";
    head = insertAtBeginning(head, 0);
    printList(head);

    std::cout << "After inserting at the end: ";
    head = insertAtEnd(head, 5);
    printList(head);

    std::cout << "After inserting at position 3: ";
    head = insertAtSpecificPosition(head, 7, 3);
    printList(head);

    deallocate(head);
    return 0;
}