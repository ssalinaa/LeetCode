#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(int value, Node* next = nullptr) {
        this->value = value;
        this->next = next;
    }
};

Node* deleteAtBeginning(Node* head) {
    if(!head) return nullptr;
    Node* toBeDeleted = head;
    head = head->next;
    delete toBeDeleted;
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

    std::cout << "After deleting the node at the beginning: ";
    head = deleteAtBeginning(head);
    printList(head);

    return 0;
}