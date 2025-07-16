#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

void traverseList(Node* head) {
    Node* current = head;
    while(current) {
        std::cout << current->data << " ";
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
    traverseList(head);

    return 0;
}