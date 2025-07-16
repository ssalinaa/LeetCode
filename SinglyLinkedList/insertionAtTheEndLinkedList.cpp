#include <iostream>

#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(int value, Node* next = nullptr) {
        this->value = value;
        this->next = next;
    }
};

Node* insertAtEnd(Node* head, int newValue) {
    Node* newNode = new Node(newValue);
    if(!head) {
        return newNode;
    }
    Node* current = head;
    while(current->next) {
        current = current->next;
    }
    current->next = newNode;
    return head;
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

    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);

    std::cout << "Original Linked list: ";
    printList(head);

    std::cout << "After inserting new node at the end: ";
    int value = 1;
    head = insertAtEnd(head, value);
    printList(head);

    return 0;
}