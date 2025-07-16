#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(int value, Node* next = nullptr) {
        this->value = value;
        this->next = next;
    }
};

Node* deleteAtEnd(Node* head) {
    if(!head) return nullptr;
    if(!head->next) {
        delete head;
        return nullptr;
    }

    Node* current = head;
    while(current->next->next) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
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

    std::cout << "After deleting the node at the end: ";
    head = deleteAtEnd(head);
    printList(head);

    return 0;
}